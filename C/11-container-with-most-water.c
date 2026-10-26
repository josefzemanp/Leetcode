int maxArea(int* height, int heightSize) {
    int leftIndex = 0;
    int rightIndex = heightSize - 1;
    int maxArea = 0;

    while(rightIndex > leftIndex){
        int area = 0;

        if(height[leftIndex] > height[rightIndex]){
            area = height[rightIndex] * (rightIndex - leftIndex);
        } else {
            area = height[leftIndex] * (rightIndex - leftIndex);
        }

        if(area > maxArea) maxArea = area;

        if(height[leftIndex] > height[rightIndex])
            rightIndex--;
        else
            leftIndex++;
    }

    return maxArea;
}
