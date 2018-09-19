#pragma once

#include <vector>

namespace YourNameHere {
    
   // Please do not modify these function signatures.
  
   int Task1_ConsecutiveHighestSum(std::vector<int> const& A, int const L);

   // Adjust the brightness of each pixel by a adding an offset. 
   // The offset is a linear function of (x,y) with a constant term c:
   //     offset = c + mx*x + my*y 
   void Task2_AdjustBrightness(
      unsigned char *inputImage, unsigned char *outputImage,
      int width, int height,
      float c, float mx = 0.0, float my = 0.0);

   void Task4_DownscaleByMax(
      unsigned char *input, unsigned char *output,
      int outputWidth, int outputHeight
   );

};