#include "CRoutine.h"



class CWaves: public CRoutine
{
    public:
        CWaves();
        ~CWaves();
        void get_config(struct routine_conf *conf);
        static void config(struct routine_conf *conf);
        void menu_min_max_change(uint8_t menu_id, int16_t new_value);
        void menu_multi_choice_change(uint8_t menu_id, uint8_t choice_id);
        void start();
        void loop(uint64_t time_us);
        void stop();

    private:

        struct chan_info
        {
            uint8_t chan_id;
            bool gap_increasing;         // true = gap between pulses is increasing, false = gap is decreasing (-> freq increasing)
            uint64_t next_pulse_time;
            int64_t pulse_gap_us;        // gap between pulses
            int64_t pulse_gap_adj_us;    // how much to change the gap by after each pulse. higher = faster
        };

        chan_info _chan[4];
        const int64_t _inital_pulse_gap_us = 60000;
        void set_pulse_step_from_duration_seconds(uint16_t duration_sec);

        void channel_loop(uint64_t time_us, chan_info *chan);

        
        int64_t _pulse_step_us = 0;   
             
        bool _reset_after_waves = true;
        bool _reset = false;
};
