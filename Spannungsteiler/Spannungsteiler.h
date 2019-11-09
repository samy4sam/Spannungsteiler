

#ifndef H_SPANNUNGSTEILER
#define H_SPANNUNGSTEILER

class Spannungsteiler
{
  public:
    enum erow {E3,E6,E12,E24,E48,E96,E192};
    Spannungsteiler();
    void setVol1(float vol);
    void setVol2(float vol);
    void setCur(float cur);
    void setERow(enum Spannungsteiler::erow);
    float getRes1() const;
    float getRes2() const;
    void reset();
    void doCalc();

  private:
    int erowValue;
    float vol1;
    float vol2;
    float current;
    float res1;
    float res2;
};
#endif
