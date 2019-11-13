## Some records
* when judge the specific bit plane is '1' or '0', you should directly judge the bit instead of using ">=",  
  since **A intensity value can be large than 32 but without 1 in bit plane 6**.  
  So, it's something like:  
  ```*it>>(bitPlane-1) & 1 == 1 ?```

* when **show different bit planes**, use:  
  ```*it = (*it>>(bitPlane-1) & 1 == 1 ? 255 : 0);```  
  and use:  
  ```*it = (*it>>(bitPlane-1) & 1 == 1 ? 1<<(bitPlane-1) : 0);```  
  when **reconstruct image** using several bit planes.

* Last, I don't know why the original image will change when the copied image was changed  
  (The image was encapsulated in a class,  
  and the copied image was initialized by a **copy constructor**)
