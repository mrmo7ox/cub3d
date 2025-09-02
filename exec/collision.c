#include "../cub.h"

bool check_wall_at_position(t_main *main, double x, double y)
{
    int map_x = (int)(x / main->map->tsize);
    int map_y = (int)(y / main->map->tsize);
    
    if (map_y < 0 || map_y >= (int)ft_dplen(main->map->content) ||
        map_x < 0 || map_x >= (int)ft_strlen(main->map->content[map_y]))
        return (true);
    
    return (main->map->content[map_y][map_x] == '1');
}

bool check_collision_with_radius(t_main *main, double x, double y)
{
    double radius = main->p->size / 2.0;
    int num_points = 8;

    if (check_wall_at_position(main, x, y))
        return true;
    
    for (int i = 0; i < num_points; i++)
    {
        double angle = 2 * PI * i / num_points;
        double check_x = x + cos(angle) * radius;
        double check_y = y + sin(angle) * radius;
        
        if (check_wall_at_position(main, check_x, check_y))
            return true;
    }
    
    double corners[4][2] = {
        {x - radius, y - radius},
        {x + radius, y - radius},
        {x - radius, y + radius},
        {x + radius, y + radius}
    };
    
    for (int i = 0; i < 4; i++)
    {
        if (check_wall_at_position(main, corners[i][0], corners[i][1]))
            return true;
    }
    
    return false;
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
    
    if (can_move_to(main, *final_x, target_y))
    {
        *final_y = target_y;
    }
}

void collosion(t_main *main)
{
    if (check_collision_with_radius(main, main->p->x, main->p->y))
    {
        double step = 0.5;
        bool found_free = false;
        
        for (int radius = 1; radius <= 20 && !found_free; radius++)
        {
            for (int angle = 0; angle < 360; angle += 15)
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