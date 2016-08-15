//
//  test_input.cpp
//  splashkit
//
//  Created by Andrew Cain on 15/08/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#include "test_input.hpp"

#include "input.h"
#include "graphics.h"
#include "text.h"

void run_input_test()
{
    rectangle rect = { 230.0f, 50.0f, 200.0f, 30.0f };
    
    window w1 = open_window("Test Input", 600, 600);
    window w2 = open_window("Test Input Window 2", 600, 600);
    
    load_font("hara", "hara.ttf");
    load_font("taroko", "Taroko.ttf");
    
    start_reading_text(rect);
    
    set_current_window(w2);
    
    start_reading_text(rect);
    
    while ( reading_text(w1) || reading_text(w2) )
    {
        process_events();
        
        set_current_window(w1);
        
        clear_screen(COLOR_WHITE);
        draw_text("Enter english string: ", COLOR_NAVY, "hara", 18, 30, 50);
        draw_collected_text(COLOR_BLACK, font_named("hara"), 18, 230, 50, option_defaults());
        
        if ( not reading_text(w1) )
        {
            draw_text(string("Read: "), COLOR_BLUE, "hara", 18, 30, 80);
            draw_text(text_input(w1), COLOR_BLUE, "hara", 18, 30, 110);
        }
        
        set_current_window(w2);
        clear_screen(COLOR_WHEAT);
        draw_text("Enter Japanese string: ", COLOR_NAVY, "hara", 18, 30, 50);
        draw_collected_text(COLOR_BLACK, font_named("taroko"), 18, 230, 50, option_defaults());
        
        if ( not reading_text(w2) )
        {
            draw_text(string("Read: "), COLOR_BLUE, "hara", 18, 30, 80);
            draw_text(text_input(w2), COLOR_BLUE, "taroko", 18, 30, 110);
        }
        
        refresh_screen();
    }
    
    close_window("Test Input");
    close_window("Test Input Window 2");
    
    free_all_fonts();
}