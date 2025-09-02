#include "../cub.h"

void render_3d_view(t_main *main)
{
    double fov = FOV * PI / 180;
    int num_rays = WIDTH;
    
    for (int x = 0; x < num_rays; x++)
    {
        double ray_angle = main->p->rotation_angle - (fov / 2) + ((double)x * fov / (double)num_rays);
        ray_angle = normalize_angle(ray_angle);
        
        double dist = cast_ray(main, ray_angle);
        
        double angle_diff = ray_angle - main->p->rotation_angle;
        if (angle_diff > PI) angle_diff -= 2 * PI;
        if (angle_diff < -PI) angle_diff += 2 * PI;
        double corrected_dist = dist * cos(angle_diff);
        
        if (corrected_dist <= 0.1)
            corrected_dist = 0.1;
        
        double wall_height = (main->map->tsize * HEIGHT) / corrected_dist;
        
        int wall_start = (int)((HEIGHT / 2) - (wall_height / 2)) - 1;
        int wall_end = (int)((HEIGHT / 2) + (wall_height / 2)) + 1;
        
        if (wall_start < 0) wall_start = 0;
        if (wall_end >= HEIGHT) wall_end = HEIGHT - 1;
        
        int wall_color = 0x3b2b1d;
        double shade_factor = 1.0 - (corrected_dist / (main->map->tsize * 20));
        if (shade_factor < 0.1) shade_factor = 0.1;
        if (shade_factor > 1.0) shade_factor = 1.0;
        
        int r = (int)(((wall_color >> 16) & 0xFF) * shade_factor);
        int g = (int)(((wall_color >> 8) & 0xFF) * shade_factor);
        int b = (int)((wall_color & 0xFF) * shade_factor);
        int shaded_color = (r << 16) | (g << 8) | b;
        
        for (int y = 0; y < HEIGHT; y++)
        {
            if (y < wall_start)
                draw_pxl(main->img, x, y, main->colors->c);
            else if (y <= wall_end)
                draw_pxl(main->img, x, y, shaded_color);
            else
                draw_pxl(main->img, x, y, main->colors->f);
        }
    }
}