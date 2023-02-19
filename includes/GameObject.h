// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#ifndef GAME_OBJECT
#define GAME_OBJECT

class Game_Object{
    
    public:

        static char arrow();
        static char health();
        static char pod();
        static char empty();
        static char trail();
        static char rock();

        virtual char getType() = 0;
        virtual int  getXPos() const;
        virtual int  getYPos() const;
        virtual int  getWidth() = 0;  // add a getWidth() member function
        virtual int  getHeight() = 0;
    
};

#endif