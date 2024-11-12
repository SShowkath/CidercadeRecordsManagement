# Arcade Game Records Management System

## Core Components

### Binary Search Tree (BinTree)
- Template-based implementation for flexible data types
- Maintains records in alphabetical order by game name
- Includes standard BST operations with specialized game management features
- Implements both recursive and iterative traversal methods

### Game Class
- Manages individual game records with attributes:
  ```cpp
  string name       // Game title
  int score        // High score
  string initials  // Player initials
  int plays        // Number of times played
  float revenue    // Calculated as plays/4.0 ($0.25 per play)
  ```
- Includes comparison operators for BST ordering
- Custom output stream operator for formatted display

### Node Template Class
- Generic node implementation for BST structure
- Contains:
  ```cpp
  T data           // Template data type
  Node<T>* left    // Left child pointer
  Node<T>* right   // Right child pointer
  ```
- Includes comparison operators for tree operations

## Implementation Details

### Tree Operations
1. **Insertion**
   - Recursive implementation
   - Maintains BST property based on game names
   - Creates new nodes for unique games

2. **Search**
   - Two variants:
     - `Search`: Returns result with detailed game info
     - `SearchNoPrint`: Boolean search for internal operations
   - Recursive implementation traversing left/right based on game name

3. **Deletion**
   - Handles three cases:
     - Leaf node deletion
     - Single child node deletion
     - Two child node deletion with successor
   - Maintains BST properties after removal

4. **Traversal Methods**
   - `printInorder`: Ascending alphabetical order
   - `printReverseOrder`: Descending alphabetical order
   - `printFile`: Breadth-first traversal for file output
   - Uses queue for breadth-first traversal implementation

### File Operations
1. **Input Processing**
   - Reads initial database file in format:
     ```
     game_name, score, initials, plays, revenue
     ```
   - Processes command file with operation codes:
     ```
     1: Insert
     2: Search
     3: Edit
     4: Delete
     5: Print (asc/des)
     ```

2. **Output Generation**
   - Saves final BST state to 'cidercade.dat'
   - Uses breadth-first traversal for file writing
   - Maintains consistent format with input structure

### Memory Management
- Dynamic allocation for BST nodes
- Proper cleanup in deletion operations
- Template design for memory efficiency

### Error Handling
- Validates file operations
- Checks for node existence before operations
- Maintains BST integrity during modifications

## Data Flow
1. Reads initial game records
2. Processes commands sequentially
3. Updates BST structure
4. Generates formatted output
5. Saves final state to file

## Performance Considerations
- BST operations average case: O(log n)
- Worst case (unbalanced tree): O(n)
- Space complexity: O(n) for n games
- No self-balancing implementation
