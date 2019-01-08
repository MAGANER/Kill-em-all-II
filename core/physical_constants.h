#pragma once
/*
these variables are used to scale 
MKS(meter-kilogram-second) values
to standart render values,such as
pixels. 
it is needed, because box2D uses MKS value system.



example:
a* SCALE = b pixels
a/ SCALE = b meters
*/
const float SCALE = 30.0f;
const float DEG = 57.29577f;