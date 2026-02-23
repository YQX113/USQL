# USQL

USQL is a C++ plugin that integrates MariaDB directly into Unreal Engine 5.

![HighresScreenshot_2026.02.22-22.45.11](https://github.com/YQX113/USQL/blob/main/Image/HighresScreenshot_2026.02.22-22.45.11.png)

------

## Supported Versions

- Unreal Engine 5.6 – 5.7
- MariaDB 11.4.10
- Windows x64



## Installation

1. Copy plugin to:`YourProject/Plugins`

2. Enable USQL plugin in the plugin list![Plugin](C:\Users\Administrator\Desktop\Plugin.png)

3. Create nodes in the blueprint and use

   ![BP_ThirdPersonCharacter_EventGraph_00006](C:\Users\Administrator\Desktop\BP_ThirdPersonCharacter_EventGraph_00006.png)

![usql_I](C:\Users\Administrator\Desktop\usql_I.png)



## Complete blueprint nodes

![BP_I](C:\Users\Administrator\Desktop\BP_I.png)

![BP_II](C:\Users\Administrator\Desktop\BP_II.png)



## Note

1、Both sending and receiving data use utf8mb4 encoding

2、Stmt

![usql_II](C:\Users\Administrator\Desktop\usql_II.png)

![usql_III](C:\Users\Administrator\Desktop\usql_III.png)

![usql_IV](C:\Users\Administrator\Desktop\usql_IV.png)

3、Please strictly follow the naming rules set by MariaDB official

https://mariadb.com/docs/server/reference/sql-structure/sql-language-structure/identifier-names
