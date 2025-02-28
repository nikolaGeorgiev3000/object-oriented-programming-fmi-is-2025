#include <iostream>

struct Box
{
   double height;
   double width;
   double length;
};

struct Warehouse
{
   char name[1024];
   Box b1;
   Box b2;
};

int main()
{
//    Warehouse w = { "Ekont", { 1, 2, 3 }, { 4, 5, 3 } };

//    std::cout << w.name;

   // Arrays of objects:

   Box arr1[30]; // 30 boxes
   Box* arr2 = new Box[20]; // 20 boxes in the dynamic memory

   std::cin >> arr1[0].height >> arr2[3].width;
   
   std::cout << arr1[0].height << " " << arr2[3].width << std::endl;

   // Free the heap
   delete[] arr2;
}