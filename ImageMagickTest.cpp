// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Magick++.h>
#include <fstream>


int _tmain(int argc, _TCHAR* argv[])
{

        std::ifstream is;

        std::filebuf *fb = is.rdbuf();

        fb->open(argv[1], std::ios::in | std::ios::binary | std::ios::ate);

        if (fb->is_open())
        {
            std::streamsize data_size = is.tellg();
            is.seekg(0);

            char *data_buffer = new char[data_size];

            is.read(data_buffer, data_size);

            // Create a blob to store the image
            Magick::Blob blob;

            // Prime the blob with the image data
            blob.update(data_buffer, data_size);

            Magick::Image magImage;

            // Read the blob into the image
            magImage.read(blob);

            delete data_buffer;
        }


    return 0;
}

