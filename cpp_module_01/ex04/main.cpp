//
// Created by Yeshin Lee on 2022/01/01.
//

#include <iostream>
#include <fstream>

std::string crop_filename(std::string filename) {
    std::size_t pos = filename.rfind('.');

    return (filename.substr(0, pos));
}

void ft_replace(std::string filename, std::string s1, std::string s2) {
    int             located_s1 = -1;
    std::string     front;
    std::string     behind;
    std::string     crop_name;
    std::string     read_line;
    std::ifstream   readFile;
    std::ofstream   writeFile;

    crop_name = crop_filename(filename);
    readFile.open(filename);
    writeFile.open(crop_name + ".replace", std::ios::app);

    if (readFile.is_open())
    {
        if (s1 == s2)
        {
            while (!(readFile.eof()))
            {
                getline(readFile, read_line);
                writeFile.write(read_line.c_str(), read_line.length());
                writeFile.write("\n", 1);
            }
        }
        else
        {
            while (!(readFile.eof()))
            {
                getline(readFile, read_line);
                while ((located_s1 = read_line.find(s1)) != -1)
                {
                    front = read_line.substr(0, located_s1);
                    writeFile.write(front.c_str(), front.length());
                    writeFile.write(s2.c_str(), s2.length());
                    behind = read_line.substr(located_s1+s1.length(), read_line.length());
                    read_line = behind;
                }
                writeFile.write(read_line.c_str(), read_line.length());
                writeFile.write("\n", 1);
            }
        }
        readFile.close();
        writeFile.close();
    }
}

int check_validation(int ac, char **av) {
    if ((ac != 4) || !av)
        return 1;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            if (!((av[i][j] > 32) && (av[i][j] < 127)))
                return 1;
        }
    }
    return 0;
}

int main(int ac, char **av) {
    std::string filename;
    std::string s1;
    std::string s2;

    if (check_validation(ac, av))
        return 0;
    filename = av[1];
    s1 = av[2];
    s2 = av[3];

    ft_replace(filename, s1, s2);

    return 0;
}
