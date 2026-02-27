# USQL

USQL is a C++ plugin that integrates MariaDB directly into Unreal Engine 5.

![HighresScreenshot_2026.02.22-22.45.11](Image/HighresScreenshot_2026.02.22-22.45.11.png)

------

## Supported Versions

- Unreal Engine 5.6 – 5.7
- MariaDB 11.4.10
- Windows x64

<br>

## Installation

1. Ensure MariaDB has been downloaded and installed, and the service is running.
   https://mariadb.org/download/?t=mariadb&p=mariadb&r=12.2.2&os=windows&cpu=x86_64&pkg=msi&mirror=xtom_fre

2. Copy plugin to:`YourProject/Plugins`

3. Enable USQL plugin in the plugin list![I.png](Image/Installation/I.png)

4. Create nodes in the blueprint and use (Complete blueprint nodes_CreateUSQLObject)

![II.png](Image/Installation/II.png)

![III.png](Image/Installation/III.png)

<br>

## Complete blueprint nodes

1. Blueprint Node Path：`..\Content\ThirdPerson\Blueprints\BP_ThirdPersonCharacter`
   
2. The image is too large and the preview may not display properly. Please download and watch it

![BP_I.png](https://github.com/YQX113/USQL/blob/df51479d5d8c8cdaba8cdcabc55b51ac73e93fe3/Image/Complete%20blueprint%20nodes/BP_I.png)

![BP_II.png](https://github.com/YQX113/USQL/blob/f661ba3f0ca3c6ada6f5231b2adf69f8fbe28fdd/Image/Complete%20blueprint%20nodes/BP_II.png)

<br>

## Node Annotation

1.CreateUSQLObject
![CreateUSQLObject.png](Image/Note/CreateUSQLObject.png)

2.SELECT
![SELECT.png](Image/Note/SELECT.png)

3.Query
![Query+Res.png](Image/Note/Query+Res.png)

4.Stmt
![usql_I.png](Image/Note/usql_I.png)
![usql_II.png](Image/Note/usql_II.png)
![usql_III.png](Image/Note/usql_III.png)

-----
> [!NOTE]
> · Both sending and receiving data use utf8mb4 encoding \
> · Please strictly follow the naming rules set by MariaDB official \
>   https://mariadb.com/docs/server/reference/sql-structure/sql-language-structure/identifier-names \
> · One connection corresponds to one thread. If you need to perform parallel queries, please use the "Create USql Object" node to create a new connection for querying.
