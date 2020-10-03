/*
    case for the Latency Measure device

	(c) 2020 by Christian.Lorenz@gromeck.de


	This file is part of LatencyMeasure.

    LatencyMeasure is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    LatencyMeasure is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with LatencyMeasure.  If not, see <https://www.gnu.org/licenses/>.

*/

// increase the number of faces to make thinks smoother
$fn = 100;

// what part should we generate?
generate_lower_shell = false;
generate_upper_shell = false;
generate_buttons = true;
generate_sensorcase = true;
generate_sensormount = true;
generate_sensormount_clip_long = true;
generate_sensormount_clip_short = true;
generate_sensormount_clip_short_2nd = true;

// render text?
use_text = false;

// the gap used to place elements
gap = 5;
boss_draft_rel = 1.1;
case_edge_radius_rel = 1.5;
slackness_screw = 0.1;
slackness_slide = 0.2;
slackness_snap = 0.2;
text_depth = 0.1;
title = "Latency Measure";
font_font = "Roboto Mono:style=Bold";
snap_height = 1.0;

// the dimension of the case itself
case_width = 80;
case_depth = 50;
case_snap_width = case_width * 3 / 4 * 4 / 3 * 1 / 2;
case_snap_depth = case_depth * 3 / 4 * 4 / 3 * 1 / 2;
case_lower_height = 20;
case_upper_height = 5;
case_thickness = 1.5;
case_edge_radius = case_thickness * case_edge_radius_rel;
case_border_height = 0;

// PCB mounts
// offsets x & y are meassured from the inside of the case to the hole
// w & h are meassured from hole to hole center
pcbmount_x = 5;
pcbmount_y = 5;
pcbmount_w = 50;
pcbmount_h = 40;
pcbmount_boss_radius = 2.0;
pcbmount_boss_height = 3;
pcbmount_hole_radius = 1 - slackness_screw;

// USB connector
usbport_x = 0;
usbport_y = 20;
usbport_z = 8;
usbport_width = 8.0;
usbport_height = 3.2;
usbport_edge_radius = 0.5;

// sensor connector (cinch)
sensorport_x = 0;
sensorport_y = 10;
sensorport_z = 11;
sensorport_radius = 5.0;

// PCB connectors
connector_radius = 0.8;

// the dimension of the display inner/outer [mm]
display_inner_width = 30;
display_inner_height = 11;
display_inner_thickness = 1;
display_outer_width = 38;
display_outer_height = 12;
display_outer_thickness = display_inner_thickness + 1;

// offset of the visible part of the display
display_inner_offset_x = 5;
display_inner_offset_y = 0.5;

// offset of the display on the frontside of the case
display_outer_offset_x = (case_width - display_inner_width) / 2 - display_inner_offset_x;
display_outer_offset_y = (case_depth - display_inner_height) / 5 * 1 - display_inner_offset_y;

// LED
led_count = 1;
led_radius = 3/2;
led_height = 4.5;
led_offset = 2 * 2.54;
led_gap = led_offset - 2 * led_radius;
led_outer_offset_x = display_outer_offset_x + display_inner_offset_x +display_inner_width +
    (case_width - (display_outer_offset_x + display_inner_offset_x + display_inner_width)) / 2 - led_radius;
led_outer_offset_y = display_outer_offset_y + display_outer_height / 2 - led_radius;


// the dimension of the buttons
button_count = 3;
button_radius = 4;
button_offset = 5 * 2.54;
button_slackness = slackness_slide;
button_gap = button_offset - 2 * button_radius;
button_outer_offset_x = (case_width - 2 * button_radius * button_count - (button_gap * (button_count - 1))) / 2;
button_outer_offset_y = display_outer_offset_y + display_outer_height + 2 * button_radius;
button_pin_height = 5;
button_pin_radius = 1.25;
button_edge_radius = 0.5;
button_text = [ "🡇", "🡆", "Reset" ];
button_size = [ button_radius, button_radius, button_radius / 2 ];
button_font = [ "Symbola:style=Bold", "Symbola:style=Bold", font_font ];

// the dimension of the sensor case
sensorcase_thickness = 1.2;
sensorcase_diode_radius = 2.55;
sensorcase_diode_height = 7.5;
sensorcase_diode_gap = 8;
sensorcase_radius = 2.5 * sensorcase_diode_radius;
sensorcase_edge_radius = 0.25;

// dimensions of the sensor mount
sensormount_thickness = 1.5 * sensorcase_thickness;
sensormount_radius = sensorcase_radius + sensormount_thickness + slackness_snap;
sensormount_cable_radius = 1.5;
sensormount_edge_radius = 0.25;

// the hanger variant
sensormount_bar_length = 200;
sensormount_bar_width = sensormount_radius * 2;
sensormount_slot_width = 3.0;
sensormount_slot_slackness = slackness_slide;
sensormount_clip_boss_height = 10;
sensormount_clip_hole_radius = sensormount_slot_width / 2 - slackness_screw;
sensormount_clip_boss_radius = 3.0;
sensormount_clip_bar_height = 30;
sensormount_clip_bar_length = 2.5 * sensormount_clip_bar_height;
sensormount_clip_bar_width = sensormount_bar_width;

// some dimensions depend from ones above
sensorcase_height = sensorcase_diode_height + sensorcase_diode_gap;
sensormount_height = sensorcase_height - sensorcase_thickness + sensormount_thickness;

echo("sensorcase_height=",sensorcase_height);
echo("sensormount_height",sensormount_height);
echo("sensormount_bar_length=",sensormount_bar_length);
echo("sensormount_bar_width=",sensormount_bar_width);

module make_rounded_square(length,width,thickness,roundedfront = false,roundedback = false)
{
    linear_extrude(thickness) {
        if (roundedfront)
            translate([width/2,0,0])
                circle(width / 2);
        if (roundedback)
            translate([length - width / 2,0,0])
                circle(width / 2);

        translate([roundedfront ? width / 2 : 0,-width / 2,0])
            square([
                length - (roundedfront ? width / 2 : 0) - (roundedback ? width / 2 : 0),
                width],center = false);
    }
}

module make_rounded_box(height,width,depth,radius = 0)
{
    linear_extrude(height)
        if (radius)
            minkowski() {
                translate([radius,radius,0])
                    square([
                        width - 2 * radius,
                        depth - 2 * radius
                        ],center = false);
                circle(radius);
            }
        else
            square([width,height]);
}

/*
**  make a prism
*/
module make_prism(length,width,height,draft = 0)
{
    polyhedron(
        points = [
            [0,0,0],
            [length,0,0],
            [length,width,0],
            [0,width,0],
            [draft,width / 2,height],
            [length - draft,width / 2,height] ],
        faces=[
            [0,1,2,3],
            [5,4,3,2],
            [0,4,5,1],
            [0,3,4],
            [5,2,1]]
           );
}

/*
**  make a button
**
**  a flat button will be at the same height as the surface of the case
**  a non-flat button will be raised by the case_thickness over the case surface
*/
module make_button(flat = false)
{
    button_height = case_thickness * ((flat) ? 3 : 4);
    translate([button_radius + case_thickness,button_radius + case_thickness,0]) {
        difference() {
            union() {
                // the body of the button
                translate([0,0,button_edge_radius])
                    minkowski() {
                        cylinder(
                            button_height - button_edge_radius * 2,
                            button_radius - button_edge_radius,
                            button_radius - button_edge_radius,
                            center=false);
                        sphere(button_edge_radius);
                    }

                // add the ring of the button
                translate([0,0,button_height - case_thickness])
                    cylinder(
                        case_thickness,
                        button_radius + case_thickness,
                        button_radius + case_thickness,
                        center=false);
            }
            //  make it hollow
            translate([0,0,case_thickness])
                cylinder(
                        button_height,
                        button_radius - case_thickness,
                        button_radius - case_thickness,
                        center=false);
        }

        // add the pin inside
        cylinder(
                button_height + button_pin_height,
                button_pin_radius,
                button_pin_radius,
                center=false);
    }
}

/*
**  make the sensor case
*/
module make_sensorcase()
{
    translate([
            sensormount_radius,
            sensormount_radius,
            0]) {
        difference() {
            union() {
                // the body of the sensorcase
                translate([0,0,sensorcase_edge_radius])
                    minkowski() {
                        cylinder(
                            sensorcase_height - sensorcase_edge_radius * 2,
                            sensorcase_radius - sensorcase_edge_radius,
                            sensorcase_radius - sensorcase_edge_radius,
                            center=false);
                        sphere(sensorcase_edge_radius);
                    }

                // add the ring
                cylinder(
                        sensorcase_thickness,
                        sensormount_radius,
                        sensormount_radius,
                        center=false);
            }

            //  make it hollow
            translate([0,0,sensorcase_diode_height])
                cylinder(
                        sensorcase_height,
                        sensorcase_radius - sensorcase_thickness,
                        sensorcase_radius - sensorcase_thickness,
                        center=false);

            // cut out the diode
            cylinder(
                    sensorcase_height,
                    sensorcase_diode_radius,
                    sensorcase_diode_radius,
                    center=false);
        }
    }
}

/*
**  make the sensor mount to hang on the display
*/
module make_sensormount()
{
    translate([0,sensormount_radius,0]) {
        difference() {
            union() {
                // add the bar
                make_rounded_square(sensormount_bar_length,sensormount_bar_width,sensormount_thickness,true,true);

                // the body of the mount
                translate([sensormount_bar_width / 2,0,0])
                    cylinder(
                        sensormount_height,
                            sensormount_radius,
                            sensormount_radius,
                            center=false);

                // add the gussets
                translate([
                        sensormount_bar_length / 2 + slackness_slide,
                        -sensormount_thickness / 2,
                        0])
                    rotate([90,0,180])
                        linear_extrude(sensormount_thickness)
                            polygon([
                                    [0,0],
                                    [sensormount_bar_length / 2,0],
                                    [sensormount_bar_length / 2,sensormount_height]
                            ]);
            }

            //  make it hollow
            translate([sensormount_bar_width / 2,0,sensormount_thickness])
                cylinder(
                        sensormount_height,
                        sensormount_radius - sensormount_thickness,
                        sensormount_radius - sensormount_thickness,
                        center=false);

            // cut out the cable hole
            translate([sensormount_bar_width / 2,0,0])
                cylinder(
                        sensormount_thickness,
                        sensormount_cable_radius,
                        sensormount_cable_radius,
                        center=false);

            // cut out the slot
            translate([sensormount_bar_length / 2 - sensormount_bar_width / 2,0,0])
                make_rounded_square(sensormount_bar_length / 2,
                        sensormount_slot_width,
                        sensormount_thickness,true,true);

            // engrave the title onto the mount
            if (use_text)
                translate([sensormount_bar_width,0,text_depth])
                    rotate([0,180,180])
                        linear_extrude(text_depth)
                            text(
                                    title,
                                    sensormount_bar_width / 3,
                                    font = font_font,
                                    valign = "center",
                                    halign = "left"
                            );
        }
    }
}

module make_sensormount_clip()
{
    translate([0,sensormount_clip_bar_width / 2 + sensormount_thickness,0]) {
        difference() {
            union() {
                // add the notches
                # difference() {
                    translate([0,-(sensormount_clip_bar_width + 2 * sensormount_thickness + slackness_slide) / 2,0])
                        cube([
                                sensormount_clip_boss_height,
                                sensormount_clip_bar_width + 2 * sensormount_thickness + slackness_slide,
                                sensormount_thickness]);
                    translate([0,-(sensormount_clip_bar_width + slackness_slide) / 2,0])
                        cube([
                                sensormount_thickness,
                                sensormount_clip_bar_width + slackness_slide,
                                sensormount_thickness]);
                }

                // build the clip itself
                translate([sensormount_thickness,0,0]) {
                    make_rounded_square(sensormount_clip_bar_length,
                            sensormount_clip_bar_width,
                            sensormount_thickness,false,true);
                    rotate([90,-90,90])
                        make_rounded_square(sensormount_clip_bar_height,
                                sensormount_clip_bar_width,sensormount_thickness,false,true);

                    // add the gussets
                    translate([
                            sensormount_clip_bar_length / 2,
                            -sensormount_thickness / 2,
                            0])
                        rotate([90,0,180])
                            linear_extrude(sensormount_thickness)
                                polygon([
                                        [0,0],
                                        [sensormount_clip_bar_length / 2,0],
                                        [sensormount_clip_bar_length / 2,sensormount_clip_bar_height]
                                ]);

                     // add the screw boss
                    translate([
                            0,
                            0,
                            sensormount_clip_bar_height - sensormount_clip_bar_width / 2])
                        rotate([90,0,90])
                        cylinder(sensormount_clip_boss_height,
                                sensormount_clip_boss_radius,
                                sensormount_clip_boss_radius,center=false);
                            }
             }

            translate([sensormount_thickness,0,0]) {
                // cut out the slot
                translate([
                        sensormount_clip_bar_length / 2,
                        0,
                        0])
                    linear_extrude(sensormount_thickness)
                        minkowski() {
                            square([
                                    sensormount_clip_bar_length / 2 - sensormount_clip_bar_width / 2,
                                    0.0000001
                                    ],center = false);
                            circle(sensormount_slot_width / 2);
                        }

                //  cut out the clip screw hole
                translate([
                        0,
                        0,
                        sensormount_clip_bar_height - sensormount_clip_bar_width / 2])
                    rotate([0,90,0])
                        cylinder(
                            sensormount_clip_boss_height - slackness_screw,
                            sensormount_clip_hole_radius,
                            sensormount_clip_hole_radius,
                            center=false);
            }
        }
    }
}

/*
** build one generic half shell
**
**  height       is the total net height of the shell
**  snap_border  is the negative or positive height of the inner snap border
*/
module make_case_half_shell(height,snap_border = 0)
{
    difference() {
        union() {
            // the case itself
            make_rounded_box(height,case_width,case_depth,case_edge_radius);

            // the snap border
            if (snap_border > 0)
                translate([case_thickness / 2,case_thickness / 2,height])
                    make_rounded_box(snap_border,case_width - case_thickness,case_depth - case_thickness,case_edge_radius);
        }

        // make the case hollow
        translate([case_thickness,case_thickness,case_thickness])
            make_rounded_box(
                    height + abs(snap_border),
                    case_width - 2 * case_thickness,
                    case_depth - 2 * case_thickness,
                    case_edge_radius);
        if (snap_border < 0)
            translate([case_thickness / 2 + slackness_snap / 2,case_thickness / 2 + slackness_snap / 2,height - abs(snap_border) + slackness_snap])
                make_rounded_box(
                        abs(snap_border),
                        case_width - case_thickness - slackness_snap,
                        case_depth - case_thickness - slackness_snap,
                        case_edge_radius);
    }
}

/*
** build the lower part of the case
*/
module make_case_lower_shell()
{
    difference() {
        // create the shell itself
        make_case_half_shell(case_lower_height,-case_border_height);

        // cut out the USB connector
        if (usbport_x > usbport_y)
            // usbport is on the bottom
            translate([usbport_x + case_thickness,0,usbport_z + case_thickness])
                rotate([-90,0,0])
                    make_rounded_box(case_thickness,usbport_width,
                        usbport_height,usbport_edge_radius);
        else
            // usbport is on the side
            translate([0,usbport_y + case_thickness,usbport_z + case_thickness])
                rotate([0,90,0])
                    make_rounded_box(case_thickness,usbport_height,
                        usbport_width,usbport_edge_radius);

        // cut out the sensor connector
        if (sensorport_x > sensorport_y)
            // sensorport is on the bottom
            translate([sensorport_x + case_thickness,0,sensorport_z + case_thickness])
                rotate([-90,0,0])
                    cylinder(case_thickness,sensorport_radius,sensorport_radius);
        else
            // sensorport is on the bottom
            translate([0,sensorport_y + case_thickness,sensorport_z + case_thickness])
                rotate([0,90,0])
                    cylinder(case_thickness,sensorport_radius,sensorport_radius);
    }

    // add mouting holes
    translate([case_thickness,case_thickness,case_thickness])
        for (x = [pcbmount_x,pcbmount_x + pcbmount_w]) {
            for (y = [pcbmount_y,pcbmount_y + pcbmount_h]) {
                translate([x,y,0])
                    difference() {
                        cylinder(pcbmount_boss_height,
                                pcbmount_boss_radius * boss_draft_rel,
                                pcbmount_boss_radius);
                        cylinder(pcbmount_boss_height,
                                pcbmount_hole_radius,
                                pcbmount_hole_radius);
                    }
            }
        }

    // add snaps on the long sides
    if (case_border_height == 0) {
        for (side = [-1,+1])
            translate([(case_width - case_snap_width) / 2,case_depth / 2 + side * (case_depth / 2 - case_thickness),case_lower_height - snap_height])
                rotate([90 * side,0,0])
                    translate([0,-snap_height,0])
                        make_prism(case_snap_width,snap_height * 2,snap_height,snap_height);
    }
}


/*
**  build the upper part of the case
*/
module make_case_upper_shell()
{
    difference() {
        // create the shell itself
        make_case_half_shell(case_thickness,case_border_height);

        // cut out the display
        translate([
                display_outer_offset_x + display_inner_offset_x,
                display_outer_offset_y + display_inner_offset_y,
                0])
            cube([
                display_inner_width,
                display_inner_height,
                case_thickness],center=false);

        // cut out the LED
        translate ([led_outer_offset_x,led_outer_offset_y,0])
            for (led = [0:led_count - 1]) {
                translate([led_radius,led * led_offset + led_radius,0])
                cylinder(case_thickness,led_radius,led_radius);
            }

        // engrave the test LED caption
        if (use_text)
            translate([led_outer_offset_x + led_radius,led_outer_offset_y + 4 * led_radius,text_depth])
                rotate([0,180,180])
                    linear_extrude(text_depth)
                        text(
                                "Test LED",
                                led_radius,
                                font_font,
                                valign = "center",
                                halign = "center"
                        );

        // cut out the buttons
        translate ([button_outer_offset_x,button_outer_offset_y,0])
            for (button = [0:button_count - 1]) {
                translate([
                        button * button_offset + button_radius + button_slackness / 2,
                        button_radius + button_slackness / 2,
                        0])
                    cylinder(case_thickness,
                            button_radius + button_slackness / 2,
                            button_radius + button_slackness / 2);
                        // engrave the title onto the mount

                // engrave the button captions
                if (use_text)
                    translate([
                            button * button_offset + button_radius + button_slackness / 2,
                            3 * button_radius,
                            text_depth])
                        rotate([0,180,180])
                            linear_extrude(text_depth)
                                text(
                                        button_text[button],
                                        button_size[button],
                                        button_font[button],
                                        valign = "center",
                                        halign = "center"
                                );
            }

            // engrave the title onto the case
            if (use_text)
                translate([case_depth * 0.1,display_outer_offset_y / 2,text_depth])
                    rotate([0,180,180])
                        linear_extrude(text_depth)
                            text(
                                    title,
                                    case_depth / 20,
                                    font_font,
                                    valign = "center",
                                    halign = "left"
                            );
    }

    // add a mounting frame for the display
    translate ([
            display_outer_offset_x - case_thickness,
            display_outer_offset_y - case_thickness,
            case_thickness]) {
        difference() {
            cube([
                display_outer_width + 2 * case_thickness,
                display_outer_height + 2 * case_thickness,
                display_outer_thickness]);
            translate([case_thickness,case_thickness,0]) cube([
                display_outer_width,
                display_outer_height,
                display_outer_thickness]);
        }
    }

    // add LED rings
    translate ([led_outer_offset_x,led_outer_offset_y,0])
        for (led = [0:led_count - 1]) {
            translate([
                    led * led_offset + led_radius,
                    led_radius,
                    case_thickness])
                difference() {
                    cylinder(led_height,
                        led_radius + case_thickness,
                        led_radius + case_thickness);
                    cylinder(led_height,
                        led_radius,
                        led_radius);
                }
        }

    // add button rings
    translate ([button_outer_offset_x,button_outer_offset_y,0])
        for (button = [0:button_count - 1]) {
            translate([
                    button * button_offset + button_radius + button_slackness / 2,
                    button_radius + button_slackness / 2,
                    case_thickness])
                difference() {
                    cylinder(case_thickness,
                        button_radius + case_thickness,
                        button_radius + case_thickness);
                    cylinder(case_thickness,
                        button_radius + button_slackness / 2,
                        button_radius + button_slackness / 2);
                }
        }

    // add barriers on short sides
    if (case_border_height == 0) {
        for (side = [-1,+1])
            translate([case_width / 2 + side * (case_width / 2 - case_thickness * 3 / 2 - slackness_snap),2 * case_edge_radius,case_thickness])
                rotate([0,0,90])
                    translate([0,-case_thickness / 2,0])
                        make_rounded_box(case_thickness,1 * case_depth - 2 * 2 * case_edge_radius,case_thickness,case_thickness / 4);
    }

    // add snap counterparts on long sides
    if (case_border_height == 0) {
        for (side = [-1,+1])
               difference() {
                // the block ...
                translate([2 * case_edge_radius,case_depth / 2 + side * (case_depth / 2 - snap_height * 2 - slackness_snap),case_thickness])
                    translate([0,-snap_height,0])
                        make_rounded_box(snap_height * 2,case_width - 2 * 2 * case_edge_radius,snap_height * 2,snap_height / 2);

                // ... and substract the snap
                translate([(case_width - case_snap_width) / 2,case_depth / 2 + side * (case_depth / 2 - snap_height * 1 - slackness_snap),case_thickness + snap_height])
                    rotate([90 * side,0,0])
                        translate([0,-snap_height,0])
                            make_prism(case_snap_width,snap_height * 2,snap_height - slackness_snap,snap_height - slackness_snap);
            }
    }
}

/*
**  build the OLED display
*/
module make_oled_SSD1306()
{
    difference() {
        translate([0,0,0])
            color("gray") cube([
                    display_outer_width,
                    display_outer_height,
                    display_outer_thickness - display_inner_thickness]);
        for (connector = [0:3]) {
            translate([
                    2.19,
                    2.19 + 2.54 * connector,
                    0])
                cylinder(display_outer_thickness,
                        connector_radius,
                        connector_radius);
            }
        }
    translate([
            display_inner_offset_x,
            display_inner_offset_y,
            display_outer_thickness - display_inner_thickness])
            color("DarkBlue")
                cube([
                display_inner_width,
                display_inner_height,
                display_inner_thickness]);
}

* translate([0,0,0]) make_oled_SSD1306();

/*
** put everthing together side by side
*/
color("silver") union()
{
    // the case itself
    if (generate_lower_shell)
        translate([0,0])
            make_case_lower_shell();

    if (generate_upper_shell)
        translate([0,case_depth + gap,0])
            make_case_upper_shell();

    if (generate_buttons)
        translate([0,(case_depth + gap) * 2,0])
                for (button = [0:button_count - 1])
                    translate([button * (button_radius * 2 + button_gap),0,0])
                        make_button((button) ? false : true);

    if (generate_sensorcase) {
        // the sensor case without any mounts
        translate([case_width + gap,0,0])
            make_sensorcase();
    }
    
    if (generate_sensormount) {
        if (generate_sensormount_clip_short) {
            // 2 short clips
            translate([case_width + gap - 2 * sensorcase_thickness,(sensorcase_radius + sensorcase_thickness)* 2 + gap,0])
                rotate([0,0,-90]) {
                    translate([-sensormount_clip_bar_length - gap,sensormount_clip_bar_width + 3 * sensorcase_thickness,0]) {
                        // 1st clip
                        rotate([0,0,180])
                            make_sensormount_clip();
                        if (generate_sensormount_clip_short_2nd) {
                            // 2nd clip
                            translate([gap,-sensormount_clip_bar_width - 3 * sensorcase_thickness,0])
                                make_sensormount_clip();
                        }
                    }
                }
        }
        if (generate_sensormount_clip_long) {
            // 1 long clip
            translate([case_width + gap + sensormount_clip_bar_width + gap + sensormount_bar_width,0,0])
                 rotate([0,0,90])
                    make_sensormount();
        }

    }
}/**/
