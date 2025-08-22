#include "../cub.h"

void render_3d_view(t_main *main)
{
    double fov = FOV * PI / 180;
    int num_rays = WIDTH;
    
    for (int x = 0; x < num_rays; x++)
    {
        double ray_angle = main->p->rotation_angle - (fov / 2) + (x * fov / num_rays);
        ray_angle = normalize_angle(ray_angle);
        double dist = cast_ray(main, ray_angle);
        dist = dist * cos(ray_angle - main->p->rotation_angle);
        double wall_height = (main->map->tsize * HEIGHT) / dist;
        int wall_start = (HEIGHT / 2) - (wall_height / 2);
        int wall_end = (HEIGHT / 2) + (wall_height / 2);
        if (wall_start < 0) wall_start = 0;
        if (wall_end >= HEIGHT) wall_end = HEIGHT - 1;
        
        for (int y = 0; y < wall_start; y++)
        {
            draw_pxl(main->img, x, y, main->colors->c);
        }
        
        for (int y = wall_start; y <= wall_end; y++)
        {
            int wall_color = 0x3b2b1d;
            
            double shade_factor = 1.0 - (dist / (main->map->tsize * 15));
            if (shade_factor < 0.2) shade_factor = 0.2;
            if (shade_factor > 1.0) shade_factor = 1.0;
            
            // int r = 0xFF * shade_factor;
            // int g = 0xFF * shade_factor;
            // int b = 0xFF * shade_factor;
            
            // wall_color = (r << 16) | (g << 8) | b;
            draw_pxl(main->img, x, y, wall_color);
        }
        
        for (int y = wall_end + 1; y < HEIGHT; y++)
        {
            draw_pxl(main->img, x, y, main->colors->f);
        }
    }
}