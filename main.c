#include "shell.h"

int main() {
    list_t *head = NULL;

    // Add nodes to the list
    add_node(&head, "First Node", 1);
    add_node(&head, "Second Node", 2);
    add_node_end(&head, "Last Node", 3);

    // Print the list
    print_list_str(head);

    // Delete a node at index 1
    delete_node_at_index(&head, 1);

    // Print the updated list
    print_list_str(head);

    // Free the list
    free_list(&head);

    return 0;
}
