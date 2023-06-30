# Canteen-Billing-Software
An efficient and easy software of placing the order and generating the invoice at a faster pace. Login credentials are required to perform operations which enhances security. The billing software can be operated in the admin or buyer mode. Just after placing the order, the bill can be generated which contains detailed information about the customer’s name, time when the invoice was generated, discount and charges. The menu of the canteen can also be viewed which is an additional feature included using graphics.h header file. All the details of customer, invoice and availability of products will be stored permanently in a file to keep track of the entire canteen management.

Setting Compiler and Graphics files-

• Download and install 32 bit gcc compiler to add graphics.

• Download the Graphics library from the link mentioned below:
https://drive.google.com/file/d/16xZBvFXf7yFjxwTpuyevK1KPuLgUeZFh/view

Open VS code -> Create a file with .cpp -> View -> Command Palette -> C/C++:Edit Configurations(UI) -> Change the compiler path to the appropriate 32 bit gcc compiler.

Under Compiler arguments add, -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

This will include the graphics for the VS code.
