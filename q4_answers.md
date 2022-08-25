# Question a

- `llrec(1->2->3->4, 5->6)`
    - `llrec(5->6, 2->3->4)`
        - `llrec(2->3->4, 6)`
            - `llrec(6, 3->4)`
                - `llrec(3->4, nullptr)`
                - `3->4`
            - `6->3->4`
        - `2->6->3->4`
    - `5->2->6->3->4`
- `1->5->2->6->3->4`

# Question b

It returns the linked list `2`, because the first if statement succeeds on the first call and it just returns the linked list `2`.
