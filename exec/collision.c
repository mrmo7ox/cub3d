#include "../cub.h"



bool check_wall_at_position(t_main *main, double x, double y)
{
    int map_x = (int)(x / main->map->tsize);
    int map_y = (int)(y / main->map->tsize);
    
    // Check boundaries
    if (map_y < 0 || map_y >= (int)ft_dplen(main->map->content) ||
        map_x < 0 || map_x >= (int)ft_strlen(main->map->content[map_y]))
        return (true);
    
    // Check if it's a wall
    if (main->map->content[map_y][map_x] == '1')
        return (true);
    
    return (false);
}

bool check_collision_with_radius(t_main *main, double x, double y)
{
    double radius = main->p->size / 2.0;
    
    // Check collision points around the player (circle approximation with 8 points)
    double check_points[8][2] = {
        {x - radius, y - radius},  // Top-left
        {x, y - radius},           // Top
        {x + radius, y - radius},  // Top-right
        {x + radius, y},           // Right
        {x + radius, y + radius},  // Bottom-right
        {x, y + radius},           // Bottom
        {x - radius, y + radius},  // Bottom-left
        {x - radius, y}            // Left
    };
    
    for (int i = 0; i < 8; i++)
    {
        if (check_wall_at_position(main, check_points[i][0], check_points[i][1]))
            return (true);
    }
    
    return (false);
}

bool can_move_to(t_main *main, double new_x, double new_y)
{
    return (!check_collision_with_radius(main, new_x, new_y));
}

void handle_wall_sliding(t_main *main, double target_x, double target_y, double *final_x, double *final_y)
{
    double current_x = main->p->x;
    double current_y = main->p->y;
    
    *final_x = current_x;
    *final_y = current_y;
    
    if (can_move_to(main, target_x, current_y))
    {
        *final_x = target_x;
    }
    
    if (can_move_to(main, current_x, target_y))
    {
        *final_y = target_y;
    }
    
    if (can_move_to(main, target_x, target_y))
    {
        *final_x = target_x;
        *final_y = target_y;
    }
}

void collosion(t_main *main)
{

    if (check_collision_with_radius(main, main->p->x, main->p->y))
    {
        double step = 1.0;
        bool found_free = false;
        
        for (int radius = 1; radius <= 10 && !found_free; radius++)
        {
            for (int angle = 0; angle < 360; angle += 45)
            {
                double test_x = main->p->x + cos(angle * PI / 180) * radius * step;
                double test_y = main->p->y + sin(angle * PI / 180) * radius * step;
                
                if (can_move_to(main, test_x, test_y))
                {
                    main->p->x = test_x;
                    main->p->y = test_y;
                    found_free = true;
                    break;
                }
            }
        }
    }
}

bool move_player_with_collision(t_main *main, double target_x, double target_y)
{
    double final_x, final_y;
    
    if (can_move_to(main, target_x, target_y))
    {
        main->p->x = target_x;
        main->p->y = target_y;
        return (true);
    }
    handle_wall_sliding(main, target_x, target_y, &final_x, &final_y);    
    if (final_x != main->p->x || final_y != main->p->y)
    {
        main->p->x = final_x;
        main->p->y = final_y;
        return (true);
    }
    
    return (false);
}