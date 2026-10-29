#include <stdio.h>
#include <stdlib.h>
#include "gates.h"
// clear errors
#define _CRT_SECURE_NO_WARNINGS

typedef struct Gate {
	int id;
	char type; // A O X N I Q
	int input1, input2; // IDS of input gates
	int output; // output of the gate
	struct Gate* next;
} Gate;

Gate* newgate(int id, char type, int input1, int input2) {
	Gate* gate = (Gate*)malloc(sizeof(Gate));
	gate->id = id;
	gate->type = type;
	gate->input1 = input1;
	gate->input2 = input2;
	gate->output = -1; // output not calculated yet
	gate->next = NULL;
	return gate;
}

	//find gate by its ID by walking the list from the head
	static Gate* find_gate(Gate * head, int id) {
		for (Gate* gate = head; gate != NULL; gate = gate->next) {
			if (gate->id == id) {
				return gate;
			}
		}
		return NULL;
	}

	// value of the gate with this ID (error if it doesn't exist yet)
	static int value_of(Gate* head, int id, int asker) {
		Gate* src = find_gate(head, id);
		if (src == NULL || src->id >= asker) {
			fprintf(stderr, "Gate %d uses gate %d, which isn't defined before it\n", asker, id);
			exit(1);
		}
		return src->output;
	}

	//read the file and build the list in file order (append at the tail)
	static Gate* read_circuit(const char* filename, int* count) {
		FILE* fp = fopen(filename, "r");
		if (fp == NULL) {
			perror(filename);
			exit(1);
		}

		int n;
		if (fscanf(fp, "%d\n", &n) != 1) {
			fprintf(stderr, "Bad gate cound on the line 0\n");
			exit(1);
		}

		Gate* head = NULL, * tail = NULL;
		for (int line = 1; line <= n; line++) {
			int id, input1, input2;
			char type;
			if (fscanf(fp, " %d: %c %d %d", &id, &type, &input1, &input2) != 4) {
				fprintf(stderr, "Bad gate format on line %d\n", line);
				exit(1);
			}
			Gate* gate = newgate(id, type, input1, input2);
			if (head == NULL) {
				head = tail = gate;
			}
			else {
				tail->next = gate;
				tail = gate;
			}
		}
		fclose(fp);
		*count = n;
		return head;

	}
	static void read_inputs(Gate* head) {
		for (Gate* gate = head; gate != NULL; gate = gate->next) {
			if (gate->type == 'I') {
				printf("Enter value for input gate %d: ", gate->id);
				scanf("%d", &gate->output);
			}
		}
	}

	static int simulate(Gate* head) {
		int output = -1;

		for (Gate* gate = head; gate != NULL; gate = gate->next) {
			switch (gate->type) {
			case 'I':
				break; // value already set by the user
			case 'A':
				gate->output = andGATE(value_of(head, gate->input1, gate->id), value_of(head, gate->input2, gate->id));
				break;
			case 'O':
				gate->output = orGATE(value_of(head, gate->input1, gate->id), value_of(head, gate->input2, gate->id));
				break;
			case 'X':
				gate->output = xorGATE(value_of(head, gate->input1, gate->id), value_of(head, gate->input2, gate->id));
				break;
			case 'N':
				gate->output = notGATE(value_of(head, gate->input1, gate->id));
				break;
			case 'Q':
				gate->output = value_of(head, gate->input1, gate->id);
				output = gate->output;
				break;
			default:
				fprintf(stderr, "Unknown gate type '%c' on gate %d\n", gate->type, gate->id);
				exit(1);
			}

		}
		return output;
	}

		static void free_circuit(Gate * head) {
			while (head != NULL) {
				Gate* next = head->next;
				free(head);
				head = next;
			}
		}
		int main(int argc, char *argv[]) {
			if (argc != 2) {
				printf("Usage: %s <circuit file>\n", argv[0]);
				return 1;
			}
			int n;
			Gate* head = read_circuit(argv[1], &n);
			printf("Read %d gates from %s\n", n, argv[1]);
			read_inputs(head);
			int q = simulate(head);
			printf("Output = %d\n", q);

			free_circuit(head);
			return 0;
			}