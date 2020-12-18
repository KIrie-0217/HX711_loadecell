#ifndef loadcell_h
#define loadcell_h

//class 
class loadcell{
    public:
        Pin(int pin_dout,int pin_clk);
        Cariblation(double A,double B);
        
        long offset_val;
        void Init(void);
        long Read(void);
        long Averaging(long adc,char num);
        float GetGram(char num);
        double GetGram_cal(char num);

    private:
        int dout;
        int clk;
        double tilt;
        double intercept;



};

#endif
