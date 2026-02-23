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

2. Enable USQL plugin in the plugin list![I.png](https://github.com/YQX113/USQL/blob/main/Image/Installation/I.png)

3. Create nodes in the blueprint and use

   ![II.png](https://github.com/YQX113/USQL/blob/main/Image/Installation/II.png)

![III.png](https://github.com/YQX113/USQL/blob/main/Image/Installation/III.png)



## Complete blueprint nodes
（The image is too large and the preview may not display properly. Please download and watch it）

![BP_I.png](https://github.com/YQX113/USQL/blob/main/Image/Complete%20blueprint%20nodes/BP_I.png)

![BP_II.png](https://github.com/YQX113/USQL/blob/main/Image/Complete%20blueprint%20nodes/BP_II.png)



## Note

1、Both sending and receiving data use utf8mb4 encoding

2、Stmt

![usql_I.png](https://github.com/YQX113/USQL/blob/main/Image/Note/usql_I.png)

![usql_II.png](https://github.com/YQX113/USQL/blob/main/Image/Note/usql_II.png)

![usql_III.png](https://github.com/YQX113/USQL/blob/main/Image/Note/usql_III.png)

3、Please strictly follow the naming rules set by MariaDB official

https://mariadb.com/docs/server/reference/sql-structure/sql-language-structure/identifier-names
