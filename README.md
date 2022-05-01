# MLP-Library

## Example of a multilevel pointer

<img width="700" src="./resources/resume_mlp.jpg"> 

[Explanation by @GuidedHacking](https://youtu.be/_W0xdVO8-j4)

  
## How to use the lib w/ Cheat Engine (outdated version)


1. For example, we have the following offsets:
- ( [ **X-Plane.exe** + **0x02662358** ] + **0x10** + **0x10** + **0x0** + **0x8** + **0x20** + **0x18** + **0xDC** ) -> dynamic address 

<img src="./resources/example_ce_mlp.jpg"> 
<br/>


2.  First will internally fetch and load the program's base address.

``` cpp
getWindowsInfo64("X-Plane.exe", "X-System");
```
Explanation:

**"X-Plane.exe"**: Represents the .exe of the target program (It could also be a dll or be empty, this depends on how the program is made and the variable we are looking for)

**"X-System"**: It is the name of the process (It is the same name as the process opened by Cheat Engine)
<br/><br/>
3. Set the compensation matrix. (must be in hexadecimal)
``` cpp
unsigned int flap_offsets = [0x02662358, 0x10, 0x10, 0x0, 0x8, 0x20, 0x18, 0xDC];
```

4. Pass the compensation matrix to and instance of the library, this will autoload get the dynamic address.
``` cpp
    auto my_flaps = Addy64(flap_offsets);
```

5. Now can get and write data directly to the program variable, 
``` cpp
    auto flaps = my_flaps.getFloat() // Get data
    my_flaps.setFloat(77.3) // Write data
```
