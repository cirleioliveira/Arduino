(G-CODE GENERATED BY FLATCAM v8.994 - www.flatcam.org - Version Date: 2020/11/7)

(Name: Q1078-PCB_drill.txt_cnc)
(Type: G-code from Geometry)
(Units: MM)

(Created on Monday, 20 November 2023 at 10:05)

(This preprocessor is used with a motion controller loaded with GRBL firmware.)
(It is configured to be compatible with almost any version of GRBL firmware.)


(TOOLS DIAMETER: )
(Tool: 1 -> Dia: 3.1999936)
(Tool: 2 -> Dia: 1.0668)
(Tool: 3 -> Dia: 0.889)
(Tool: 4 -> Dia: 0.9652)
(Tool: 5 -> Dia: 0.8000237999999998)

(FEEDRATE Z: )
(Tool: 1 -> Feedrate: 10.0)
(Tool: 2 -> Feedrate: 300)
(Tool: 3 -> Feedrate: 300)
(Tool: 4 -> Feedrate: 300)
(Tool: 5 -> Feedrate: 300)

(FEEDRATE RAPIDS: )
(Tool: 1 -> Feedrate Rapids: 1500)
(Tool: 2 -> Feedrate Rapids: 1500)
(Tool: 3 -> Feedrate Rapids: 1500)
(Tool: 4 -> Feedrate Rapids: 1500)
(Tool: 5 -> Feedrate Rapids: 1500)

(Z_CUT: )
(Tool: 1 -> Z_Cut: -2.5)
(Tool: 2 -> Z_Cut: -1.7)
(Tool: 3 -> Z_Cut: -1.7)
(Tool: 4 -> Z_Cut: -1.7)
(Tool: 5 -> Z_Cut: -1.7)

(Tools Offset: )
(Tool: 1 -> Offset Z: 0.0)

(Z_MOVE: )
(Tool: 1 -> Z_Move: 2.0)
(Tool: 2 -> Z_Move: 2)
(Tool: 3 -> Z_Move: 2)
(Tool: 4 -> Z_Move: 2)
(Tool: 5 -> Z_Move: 2)

(Z Toolchange: 2.0 mm)
(X,Y Toolchange: 0.0000, 0.0000 mm)
(Z Start: None mm)
(Z End: 2.0 mm)
(X,Y End: 0.0000, 0.0000 mm)
(Steps per circle: 64)
(Steps per circle: 64)
(Preprocessor Excellon: GRBL_11_no_M6)

(X range:    2.9466 ...   88.6966  mm)
(Y range:    1.7856 ...   81.4146  mm)

(Spindle Speed: 0 RPM)
G21
G90
G17
G94


G01 F10.00

M5             
G00 Z2.0000
G00 X0.0000 Y0.0000                
T1
(MSG, Change to Tool Dia = 3.2000 ||| Total drills for tool T1 = 4)
M0
G00 Z2.0000
        
G01 F10.00
M03
G00 X87.0966 Y4.7701
G01 Z-2.5000
G01 Z0
G00 Z2.0000
G00 X87.0966 Y79.7001
G01 Z-2.5000
G01 Z0
G00 Z2.0000
G00 X4.5466 Y79.7001
G01 Z-2.5000
G01 Z0
G00 Z2.0000
G00 X4.5466 Y4.7701
G01 Z-2.5000
G01 Z0
G00 Z2.0000
M05
G00 Z2.00
G00 X0.0 Y0.0


