#include "Path.h"

int main()
{
    int width, height, channels;
    unsigned char *mazeImage = stbi_load("./maze.jpg", &width, &height, &channels, 3);
    if (mazeImage == 0)
    {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    Path path;
    auto img2D = path.convertTo2D(mazeImage, width, height, channels);

    auto redPixelsCord = path.detectRedPixel(img2D);

    auto img = path.changePixel();

    path.saveToPNG(img, img2D[0].size(), img2D.size(), "test.png");

    stbi_image_free(mazeImage);
    return 0;
}