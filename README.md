# USQL

USQL is a C++ plugin that integrates MariaDB directly into Unreal Engine 5.

![HighresScreenshot_2026.02.22-22.45.11](Image/HighresScreenshot_2026.02.22-22.45.11.png)

------
## License Notice
MariaDB Connector/C is not distributed with this plugin.

Users must install MariaDB Connector/C separately in order to use database functionality.

<br>

## Supported Versions

- Unreal Engine 5.6 – 5.7
- MySQL 5.7+、MySQL 8.0+、MariaDB 10+
- Windows x64

<br>

## Installation

### 1. Install MariaDB Connector/C (Required)
   
   This plugin requires the MariaDB Connector/C client library to communicate with MySQL/MariaDB databases.

   1.1 Download MariaDB Connector/C from the official website:
    https://mariadb.com/downloads/connectors/connectors-data-access/c/

   1.2 Install the connector (64-bit version).

   1.3 After installation, locate the following directories (example): \
     `C:\Program Files\MariaDB\lib` \
     `C:\Program Files\MariaDB\lib\plugin`

   1.4 Add the above directories to your system PATH environment variable.
   
   1.5 Restarting the computer or Unreal Engine may be required for environment variable changes to take effect.
   
### 2. Copy plugin to:`YourProject/Plugins`

### 3. Enable USQL plugin in the plugin list![I.png](Image/Installation/I.png)

### 4. Create nodes in the blueprint and use (Complete blueprint nodes_CreateUSQLObject)

![II.png](Image/Installation/II.png)

![III.png](Image/Installation/III.png)

<br>

## Node Annotation

### 1.CreateUSQLObject
![CreateUSQLObject.png](Image/Note/CreateUSQLObject.png)

### 2.SELECT
![SELECT.png](Image/Note/SELECT.png)

### 3.Query
![Query+Res.png](Image/Note/Query+Res.png)

### 4.Stmt
![usql_I.png](Image/Note/usql_I.png)
![usql_II.png](Image/Note/usql_II.png)
![usql_III.png](Image/Note/usql_III.png)

## Complete blueprint nodes

#### 1. Blueprint Node Path：`..\Content\ThirdPerson\Blueprints\BP_ThirdPersonCharacter`
   
#### 2. The image is too large and the preview may not display properly. Please download and watch it

![BP_I.png](https://github.com/YQX113/USQL/blob/df51479d5d8c8cdaba8cdcabc55b51ac73e93fe3/Image/Complete%20blueprint%20nodes/BP_I.png)

![BP_II.png](https://github.com/YQX113/USQL/blob/f661ba3f0ca3c6ada6f5231b2adf69f8fbe28fdd/Image/Complete%20blueprint%20nodes/BP_II.png)

<br>

---
> [!NOTE]
> 
> **Required Runtime Libraries**
> 
> The following runtime libraries must be available in the system:
>
> - `libmariadb.dll`
> - `caching_sha2_password.dll`
>
> These libraries are included with **MariaDB Connector/C** and must be accessible through the **PATH environment variable**.
>
> ---
>
> **Encoding**
>
> Both sending and receiving data use **utf8mb4** encoding.
>
> ---
>
> **Naming Rules**
>
> Please strictly follow the official MariaDB naming rules:  
> https://mariadb.com/docs/server/reference/sql-structure/sql-language-structure/identifier-names
>
> ---
>
> **Multithreading**
>
> One connection corresponds to **one thread**.  
> If you need to perform parallel queries, please create a new connection using the **"Create USql Object"** node.
> 
> ---
>
> **FAB Purchase Link**
> 
> https://www.fab.com/listings/909fb9d9-e322-472b-856f-c987814918d6

