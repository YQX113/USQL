# USQL

USQL is a C++ plugin that integrates MariaDB directly into Unreal Engine 5.

![HighresScreenshot_2026.02.22-22.45.11](https://github.com/YQX113/USQL/blob/main/Image/HighresScreenshot_2026.02.22-22.45.11.png)

------

## Supported Versions

- Unreal Engine 5.6 – 5.7
- MariaDB 11.4.10
- Windows x64

<br>

## Installation

1. Ensure MariaDB has been downloaded and installed, and the service is running.
   https://mariadb.org/download/?t=mariadb&p=mariadb&r=12.2.2&os=windows&cpu=x86_64&pkg=msi&mirror=xtom_fre

4. Copy plugin to:`YourProject/Plugins`

5. Enable USQL plugin in the plugin list![I.png](https://github.com/YQX113/USQL/blob/main/Image/Installation/I.png)

6. Create nodes in the blueprint and use

![II.png](https://github.com/YQX113/USQL/blob/main/Image/Installation/II.png)

![III.png](https://github.com/YQX113/USQL/blob/main/Image/Installation/III.png)

<br>

## Complete blueprint nodes

1. Blueprint Node Path：`..\Content\ThirdPerson\Blueprints\BP_ThirdPersonCharacter`
   
2. The image is too large and the preview may not display properly. Please download and watch it

![BP_I.png](https://github.com/YQX113/USQL/blob/main/Image/Complete%20blueprint%20nodes/BP_I.png)

![BP_II.png](https://github.com/YQX113/USQL/blob/main/Image/Complete%20blueprint%20nodes/BP_II.png)

<br>

## Note

1、CreateUSQLObject
![usql_I.png](Image/Note/CreateUSQLObject.png)
1、Stmt

![usql_I.png](https://github.com/YQX113/USQL/blob/main/Image/Note/usql_I.png)

![usql_II.png](https://github.com/YQX113/USQL/blob/main/Image/Note/usql_II.png)

![usql_III.png](https://github.com/YQX113/USQL/blob/main/Image/Note/usql_III.png)

2、

3、、Both sending and receiving data use utf8mb4 encoding

4、Please strictly follow the naming rules set by MariaDB official

https://mariadb.com/docs/server/reference/sql-structure/sql-language-structure/identifier-names

5、One connection corresponds to one thread. If you need to perform parallel queries, please use the "Create USql Object" node to create a new connection for querying.
