#include "SentientTasks.h"

namespace YourNameHere {
  
   int Task1_ConsecutiveHighestSum(std::vector<int> const& A, int const L)
   {
      // Your code here...

      return 0;
   }

   // Adjust the brightness of each pixel by a adding an offset. 
   // The offset is a linear function of (x,y) with a constant term c:
   //     offset = c + mx*x + my*y 
   void Task2_AdjustBrightness(
      unsigned char *inputImage, unsigned char *outputImage, 
      int width, int height, 
      float c, float mx, float my)
   {
      for (int x = 0; x < width; x++)
      {
         for (int y = 0; y < height; y++)
         {
            // Calculate the adjusted brightness at this pixel
            float p_value = float(inputImage[y*width + x]); 
            float a_value = p_value + c + mx * float(x) + my * float(y);
            // Bring into range [0,255] 
            a_value = a_value < 0 ? 0 : (a_value > 255 ? 255 : a_value);
            // Copy adjusted value into the image 
            outputImage[y*width + x] = (unsigned char)a_value;
         }
      }
   }

   void Task4_DownscaleByMax(
      unsigned char *input, unsigned char *output,
      int outputWidth, int outputHeight
   )
   {
      // Your code here...
   }

};