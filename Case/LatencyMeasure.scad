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

// fragment control to make curves smooth
$fa = 6;
$fs = 0.1;
$fn = 0;

// generate the final output
final = true;
what = "case";
//what = "buttons";
//what = "sensor";
//what = "all";

// what part should we generate?
generate_pcb = (final) ? false : true;

generate_case = (final || what == "case" || what == "all") ? true : false;
generate_case_lower = true;
generate_case_upper = true;
generate_case_closed = (final) ? false : false;

generate_buttons = (what == "buttons" || what == "all") ? true : false;

generate_sensorcase = (what == "sensor" || what == "all") ? true : false;
generate_sensormount = (what == "sensor" || what == "all") ? true : false;
generate_sensormount_clip_long = (generate_sensormount && (what == "sensor" || what == "all")) ? true : false;
generate_sensormount_clip_short = (generate_sensormount && (what == "sensor" || what == "all")) ? true : false;
generate_sensormount_clip_short_2nd = (generate_sensormount && (what == "sensor" || what == "all")) ? true : false;

// select the type of usb port (square or round)
generate_usbport_round = true;

// the gap used to place elements
gap = 5;
boss_draft_rel = 1.5;
case_edge_radius_rel = 1.5;
slackness = 0.2;
slackness_screw = slackness;
slackness_led = slackness;
slackness_slide = slackness;
slackness_snap = slackness * 4;
slackness_cable = slackness;
slackness_cinch = 3 * slackness;
slackness_button = 2 * slackness;
slackness_usb = slackness;
slackness_display = slackness * 2;
text_depth = 0.1;
snap_height = 1.0;

// PCB board dimension
pcb_length = 88.25;
pcb_width = 52.25;
pcb_offset_x = 0.5;
pcb_thickness = 1.6;
pcb_button_length = 6.0;
pcb_button_width = 6.0;
pcb_button_base_height = 3.0;
pcb_button_radius = 3.0 / 2;
pcb_button_height = 9.5;
pcb_controller_length = 1.30 * 25.4;
pcb_controller_width = 0.7 * 25.4;
pcb_controller_height = 1.6;
pcb_usbport_length = 5.5;
pcb_usbport_width = 5.5;
pcb_usbport_height = 2.6;
pcb_led_height = 5.5;
pcb_led_radius = 3.0 / 2;

// usbport cutout
usbport_width = (generate_usbport_round) ? 9.0 : 12.0;
usbport_height = (generate_usbport_round) ? usbport_width : 7.0;
usbport_edge_radius = 0.5;

// the dimension of the case itself
case_thickness = 1.8;
case_edge_radius = case_thickness * case_edge_radius_rel;
case_length = 110;
case_width = pcb_width + 2 * case_thickness + 2 * case_edge_radius;
case_snap_width = case_length * 3 / 4 * 4 / 3 * 1 / 2;
case_snap_depth = case_width * 3 / 4 * 4 / 3 * 1 / 2;
case_lower_height = 26;
case_upper_height = 5;
case_border_height = 0;

// pcb mounts
pcbmount_screw_diameter = 1.7;
pcbmount_screw_length = 5.0;
pcbmount_boss_height = pcbmount_screw_length - pcb_thickness - case_thickness / 2;
pcbmount_hole_radius = pcbmount_screw_diameter / 2 - slackness_screw / 2;
pcbmount_boss_radius = pcbmount_hole_radius * 3;


echo(pcb_width / 2 - pcb_usbport_width / 2 + 2.54);

// sensor connector (cinch)
sensorport_offset_z = 0;
sensorport_height = 13.2;
sensorport_width = 10.2;
sensorport_length = 14.4;
sensorport_cinch_length = 23.0 - sensorport_length;
sensorport_cinch_radius = 8.2 / 2;
sensorport_offset_x = pcb_offset_x + pcb_length + (case_length - 2 * case_thickness - pcb_offset_x - pcb_length - sensorport_width) / 2;
sensorport_offset_y = 0;

// PCB connectors
connector_radius = 0.8;

// the dimension of the display inner/outer [mm]
display_inner_width = 25.8;
display_inner_height = 10.2;
display_inner_thickness = 1.6;
display_outer_width = 38.0;
display_outer_height = 12.2;
display_outer_thickness = display_inner_thickness + 1.4;

// offset of the visible part of the display
display_inner_offset_x = 5.2;
display_inner_offset_y = 1.0;

// offset of the display on the frontside of the case
display_outer_offset_x = 30.5;
display_outer_offset_y = 12.0;

// LED
led_count = 1;
led_radius = 3.0/2;
led_height = 4.5;

// the dimension of the buttons
button_count = 3;
button_radius = 4;
button_offset = 5 * 2.54;
button_gap = button_offset - 2 * button_radius;
button_pin_height = case_lower_height - case_thickness - pcbmount_boss_height - pcb_thickness - pcb_button_height - case_thickness / 2;
button_pin_radius = pcb_button_radius;
button_edge_radius = 0.5;

// the dimension of the sensor case
sensorcase_thickness = 1.2;
sensorcase_diode_radius = 5.0 / 2;
sensorcase_diode_height = 7.5;
sensorcase_diode_gap = 8;
sensorcase_radius = 2.5 * sensorcase_diode_radius;
sensorcase_edge_radius = 0.25;

// dimensions of the sensor mount
sensormount_thickness = 1.5 * sensorcase_thickness;
sensormount_radius = sensorcase_radius + sensormount_thickness + slackness_slide;
sensormount_cable_radius = 3.0 / 2;
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

// define the elements on the PCB
pcb_offset_y = (case_width - 2 * case_thickness - pcb_width) / 2;
pcb_elements = [
    // x offset, y offset, z offset, radius, type
    [  4.2,  9.4, 0, 2.0 / 2, "screwhole"  ],
    [  4.2, 42.4, 0, 2.0 / 2, "screwhole"  ],
    [ 83.0,  9.4, 0, 2.0 / 2, "screwhole"  ],
    [ 83.0, 42.4, 0, 2.0 / 2, "screwhole"  ],
    [ 11.8, 26.0, 0, 3.0 / 2, "hole" ],
    [ 75.3, 26.0, 0, 3.0 / 2, "hole" ],
    [ 52.7 + 0 * 5 * 2.54,33.7, 0, button_radius, "button"],
    [ 52.7 + 1 * 5 * 2.54,33.7, 0, button_radius, "button"],
    [ 52.7 + 2 * 5 * 2.54,33.7, 0, button_radius, "button"],
    [ 52.7 + 1 * 5 * 2.54,18.5, 0, button_radius, "button-int"],
    [ 24.5, 8.8, case_lower_height - case_thickness - pcb_led_height - pcbmount_boss_height - case_thickness, pcb_led_radius, "led"],
    [ 2,18.4, 11.1, 0, "controller"],
    [ 1.0,pcb_width / 2 - pcb_usbport_width / 2 + 2.54/2, 12.7, 0, "usbport"],
    ];

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
                            r = button_radius - button_edge_radius,
                            center=false);
                        sphere(button_edge_radius);
                    }

                // add the ring of the button
                cylinder(
                    case_thickness,
                    r = button_radius + case_thickness,
                    center=false);
            }
            //  drill the hole for the pin
            translate([0,0,-case_thickness])
                cylinder(
                        case_thickness * 3,
                        r = button_pin_radius + slackness_slide,
                        center=false);
        }

        // add the pin inside
        translate([0,button_radius * 3,0])
        cylinder(
                button_pin_height,
                r = button_pin_radius,
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
                            r = sensorcase_radius - sensorcase_edge_radius,
                            center=false);
                        sphere(sensorcase_edge_radius);
                    }

                // add the ring
                cylinder(
                        sensorcase_thickness,
                        r = sensormount_radius,
                        center=false);
            }

            //  make it hollow
            translate([0,0,sensorcase_diode_height])
                cylinder(
                        sensorcase_height,
                        r = sensorcase_radius - sensorcase_thickness,
                        center=false);

            // cut out the diode
            cylinder(
                    sensorcase_height,
                    r = sensorcase_diode_radius + slackness_led / 2,
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
                            r = sensormount_radius,
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
                        r = sensormount_radius - sensormount_thickness,
                        center=false);

            // cut out the cable hole
            translate([sensormount_bar_width / 2,0,-sensormount_thickness / 2])
                cylinder(
                        sensormount_thickness * 2,
                        r = sensormount_cable_radius + slackness_cable / 2,
                        center=false);

            // cut out the slot
            translate([sensormount_bar_length / 2 - sensormount_bar_width / 2,0,-sensormount_thickness / 2])
                make_rounded_square(sensormount_bar_length / 2,
                        sensormount_slot_width,
                        sensormount_thickness * 2,true,true);
        }
    }
}

module make_sensormount_clip()
{
    translate([0,sensormount_clip_bar_width / 2 + sensormount_thickness,0]) {
        difference() {
            union() {
                // add the notches
                difference() {
                    translate([0,-(sensormount_clip_bar_width + 2 * sensormount_thickness + slackness_slide) / 2,0])
                        cube([
                                sensormount_clip_boss_height,
                                sensormount_clip_bar_width + 2 * sensormount_thickness + slackness_slide,
                                sensormount_thickness]);
                    translate([-sensormount_thickness,-(sensormount_clip_bar_width + slackness_slide) / 2,-sensormount_thickness / 2])
                        cube([
                                sensormount_thickness * 2,
                                sensormount_clip_bar_width + slackness_slide,
                                sensormount_thickness * 2]);
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
                                r = sensormount_clip_boss_radius,center=false);
                }
            }

            translate([sensormount_thickness,0,0]) {
                // cut out the slot
                translate([
                        sensormount_clip_bar_length / 2,
                        0,
                        -sensormount_thickness / 2])
                    linear_extrude(sensormount_thickness * 2)
                        minkowski() {
                            square([
                                    sensormount_clip_bar_length / 2 - sensormount_clip_bar_width / 2,
                                    0.0000001
                                    ],center = false);
                            circle(sensormount_slot_width / 2);
                        }

                //  cut out the clip screw hole
                translate([
                        -slackness_screw,
                        0,
                        sensormount_clip_bar_height - sensormount_clip_bar_width / 2])
                    rotate([0,90,0])
                        cylinder(
                            sensormount_clip_boss_height - slackness_screw,
                            r = sensormount_clip_hole_radius,
                            center=false);
            }
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
                cylinder(display_outer_thickness,r = connector_radius);
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

/*
**  build the PCB components
*/
module make_pcb()
{
    translate([case_thickness + pcb_offset_x,case_thickness + pcb_offset_y,case_thickness + pcbmount_boss_height])
        union() {
            difference() {
                color("green")
                    cube([pcb_length,pcb_width,pcb_thickness],center = false);
                for (element = pcb_elements) {
                    // drill the holes
                    if (element[4] == "screwhole" || element[4] == "hole") {
                        translate([element[0],element[1],-pcb_thickness / 2])
                            cylinder(pcb_thickness * 2,r = element[3]);
                    }
                }
            }
            // add other elements
            translate([0,0,pcb_thickness])
                for (element = pcb_elements) {
                    if (element[4] == "button" || element[4] == "button-int") {
                        translate([element[0],element[1],pcb_button_base_height / 2 + element[2]])
                            color("silver")
                                cube([pcb_button_length,pcb_button_width,pcb_button_base_height],center = true);
                        translate([element[0],element[1],pcb_button_height / 2 + element[2]])
                            color("black")
                                cylinder(pcb_button_height,r = pcb_button_radius,center = true);
                    }
                    if (element[4] == "led") {
                        echo("LED legs are ",element[2],"mm");
                        translate([element[0],element[1],element[2]])
                            color("red")
                                union() {
                                    cylinder(pcb_led_height - pcb_led_radius,r = pcb_led_radius,center = false);
                                    translate([0,0,pcb_led_height - pcb_led_radius])
                                        sphere(pcb_led_radius);
                                }
                    }
                    if (element[4] == "controller") {
                        // controller socket
                        translate([element[0] + pcb_controller_length / 2,element[1] + pcb_controller_width / 2,element[2] / 2])
                            color("black")
                                difference() {
                                    translate([0,0,-pcb_controller_height / 2])
                                        cube([pcb_controller_length,pcb_controller_width,element[2] + pcb_controller_height],center = true);
                                    translate([-pcb_controller_height / 2,0,0])
                                        cube([pcb_controller_length + 2 * pcb_controller_height,pcb_controller_width - pcb_controller_height * 2,element[2]+pcb_controller_height],center = true);
                                }
                        // controller itself
                        if (1) {
                            translate([element[0],element[1],element[2]])
                                rotate([0,0,90])
                                    translate([0,-pcb_controller_length,0])
                                        import("Pro_Micro.stl",1);
                        }
                        else {
                            translate([element[0] + pcb_controller_length / 2,element[1] + pcb_controller_width / 2,pcb_controller_height / 2 + element[2]])
                                color("lightblue")
                                    cube([pcb_controller_length,pcb_controller_width,pcb_controller_height],center = true);
                        }
                    }
                    if (element[4] == "usbport") {
                        translate([element[0] + pcb_usbport_length / 2,element[1] + pcb_usbport_width / 2,pcb_usbport_height / 2 + element[2]])
                            color("silver")
                                cube([pcb_usbport_length,pcb_usbport_width,pcb_usbport_height],center = true);
                    }
                }
        }

        // the sensorport
        translate([case_thickness,case_thickness,case_thickness])
            translate([sensorport_offset_x + sensorport_width / 2,sensorport_offset_y + sensorport_length / 2,sensorport_offset_z + sensorport_height / 2]) {
                color("yellow")
                    cube([sensorport_width,sensorport_length,sensorport_height],center = true);
                color("silver")
                    translate([0,-(sensorport_length / 2 + sensorport_cinch_length / 2),0])
                        rotate([0,90,90])
                            cylinder(sensorport_cinch_length,r = sensorport_cinch_radius,center = true);
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
            make_rounded_box(height,case_length,case_width,case_edge_radius);

            // the snap border
            if (snap_border > 0)
                translate([case_thickness / 2,case_thickness / 2,height])
                    make_rounded_box(snap_border,case_length - case_thickness,case_width - case_thickness,case_edge_radius);
        }

        // make the case hollow
        if (height > case_thickness) {
            translate([case_thickness,case_thickness,case_thickness])
                make_rounded_box(
                        height + abs(snap_border),
                        case_length - 2 * case_thickness,
                        case_width - 2 * case_thickness,
                        case_edge_radius);
            if (snap_border < 0)
                translate([case_thickness / 2 + slackness_snap / 2,case_thickness / 2 + slackness_snap / 2,height - abs(snap_border) + slackness_snap])
                    make_rounded_box(
                        abs(snap_border),
                        case_length - case_thickness - slackness_snap,
                        case_width - case_thickness - slackness_snap,
                        case_edge_radius);
        }
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

        translate([case_thickness + pcb_offset_x,case_thickness + pcb_offset_y,case_thickness + pcbmount_boss_height])
            // cut out the USB connector
            translate([0,0,pcb_thickness])
                for (element = pcb_elements) {
                    if (element[4] == "usbport") {
                        if (generate_usbport_round) {
                            // round cut-out
                            translate([element[0] - pcb_usbport_length,pcb_usbport_width / 2 + element[1] + slackness_usb / 2,pcb_usbport_height / 2 + element[2] + slackness_usb / 2])
                                rotate([-90,0,-90])
                                    cylinder(pcb_usbport_length * 2,r = usbport_width / 2 + slackness_usb,center=true);
                        }
                        else {
                            // square cut-out
                            translate([element[0] - pcb_usbport_length,pcb_usbport_width / 2 + element[1] + usbport_width / 2 + slackness_usb / 2,pcb_usbport_height / 2 + element[2] + usbport_height / 2 + slackness_usb / 2])
                                rotate([-90,0,-90])
                                    make_rounded_box(pcb_usbport_length * 2,usbport_width + slackness_usb,usbport_height + slackness_usb,usbport_edge_radius);
                        }
                    }
                }

        // cut out the sensor connector
        translate([case_thickness,case_thickness,case_thickness])
            translate([sensorport_offset_x + sensorport_width / 2,sensorport_offset_y - case_thickness - case_thickness / 2,sensorport_offset_z + sensorport_height / 2])
                rotate([-90,0,0])
                    cylinder(case_thickness * 2,r = sensorport_cinch_radius + slackness_cinch);
    }

    // add mouting bosses
    translate([case_thickness + pcb_offset_x,case_thickness + pcb_offset_y,case_thickness])
        for (element = pcb_elements) {
            if (element[4] == "screwhole")
                translate([element[0],element[1],0])
                    difference() {
                        cylinder(pcbmount_boss_height,pcbmount_boss_radius * boss_draft_rel,pcbmount_boss_radius);
                        cylinder(pcbmount_boss_height * 2,r = pcbmount_hole_radius);
                    }
        }

    // add the bounds to hold the sensorport cinch plug
    translate([case_thickness,case_thickness,case_thickness])
        translate([sensorport_offset_x + sensorport_width / 2,sensorport_offset_y + sensorport_length / 2,sensorport_offset_z + sensorport_height / 2 / 2]) {
            difference() {
                cube([sensorport_width + case_thickness * 2 + slackness_slide,sensorport_length,sensorport_height / 2],center = true);
                translate([0,0,-sensorport_height / 2 / 2 / 2])
                cube([sensorport_width + slackness_slide,sensorport_length * 2,sensorport_height],center = true);
            }
        }
        
    // add the barrier to hold the sensorport cinch plug -- with a little distance for some hot glue
    translate([case_thickness,case_thickness,case_thickness])
        translate([sensorport_offset_x + sensorport_width / 2,sensorport_offset_y + sensorport_length + case_thickness * 3,sensorport_offset_z + case_thickness / 2]) {
            difference() {
                cube([sensorport_width,case_thickness * 2,case_thickness],center = true);
            }
        }
        

    // add snaps on the long sides
    if (case_border_height == 0) {
        for (side = [-1,+1])
            translate([(case_length - case_snap_width) / 2,case_width / 2 + side * (case_width / 2 - case_thickness),case_lower_height - snap_height])
                rotate([90 * side,0,0])
                    translate([0,-snap_height,0])
                        make_prism(case_snap_width,snap_height * 2,snap_height,snap_height);
    }

    // add the PCB
    if (generate_pcb)
        make_pcb();
}

/*
**  build the upper part of the case
*/
module make_case_upper_shell()
{
    difference() {
        // create the shell itself
        make_case_half_shell(case_thickness,case_border_height);

        // cut out the display window
        translate([
                display_outer_offset_x + display_inner_offset_x - slackness_display / 2,
                display_outer_offset_y + display_inner_offset_y - slackness_display / 2,
                -case_thickness / 2])
            cube([
                display_inner_width + slackness_display,
                display_inner_height + slackness_display,
                case_thickness * 2],center=false);
        // cut out the display -- make the case thickness the half
        translate([
                display_outer_offset_x - slackness_display / 2,
                display_outer_offset_y - slackness_display / 2,
                case_thickness / 2])
            cube([
                display_outer_width + slackness_display,
                display_outer_height + slackness_display,
                case_thickness * 2],center=false);


        // cut out the buttons & leds
        translate([case_thickness +  (case_length - 2 * case_thickness - pcb_offset_x - pcb_length),case_thickness + pcb_offset_y,-case_thickness / 2])
            for (element = pcb_elements) {
                translate([pcb_length - element[0],element[1],0]) {
                    if (element[4] == "button") {
                        cylinder(case_thickness * 3,r = element[3] + slackness_button / 2);
                    }
                    if (element[4] == "led") {
                        cylinder(case_thickness * 2,r = element[3] + slackness_led / 2);
                    }
                }
            }
    }

    //translate([case_thickness +  (case_length - 2 * case_thickness - pcb_offset_x - pcb_length),case_thickness + pcb_offset_y,case_thickness])
    translate([case_length - case_thickness - pcb_offset_x - pcb_length,case_thickness + pcb_offset_y,case_thickness]) {
        for (element = pcb_elements) {
            // add button rings
            if (element[4] == "button") {
                translate([pcb_length - element[0],element[1],0])
                    difference() {
                        cylinder(case_thickness,r = button_radius + case_thickness);
                        translate([0,0,-case_thickness / 2])
                            cylinder(case_thickness * 2,r = button_radius + slackness_button / 2);
                    }
            }
            // add LED rings
            if (element[4] == "led") {
                translate([pcb_length - element[0],element[1],0])
                    difference() {
                        cylinder(led_height,r = element[3] + slackness_led / 2 + case_thickness);
                        translate([0,0,-led_height / 2])
                            cylinder(led_height * 2,r = element[3] + slackness_led / 2);
                    }
                }
        }
    }

    // add barriers on short sides
    if (case_border_height == 0) {
        for (side = [-1,+1])
            translate([case_length / 2 + side * (case_length / 2 - case_thickness * 3 / 2 - slackness_snap),2 * case_edge_radius,case_thickness])
                rotate([0,0,90])
                    translate([0,-case_thickness / 2,0])
                        make_rounded_box(case_thickness,1 * case_width - 2 * 2 * case_edge_radius,case_thickness,case_thickness / 4);
    }

    // add snap counterparts on long sides
    if (case_border_height == 0) {
        for (side = [-1,+1])
            difference() {
                // the block ...
                translate([
                        2 * case_edge_radius,
                        case_width / 2 + side * (case_width / 2 - snap_height * 2 - slackness_snap),
                        case_thickness])
                    translate([0,-snap_height,0])
                        make_rounded_box(snap_height * 2,case_length - 2 * 2 * case_edge_radius,snap_height * 2,snap_height / 2);

                // ... and substract the snap
                translate([
                        (case_length - case_snap_width * 1.1) / 2,
                        case_width / 2 + side * (case_width / 2 - snap_height * 1 - slackness_snap),
                        case_thickness + snap_height])
                    rotate([90 * side,0,0])
                        translate([0,-snap_height,0])
                            make_prism(case_snap_width * 1.1,snap_height * 2,snap_height,snap_height);
            }
    }

    // add a mounting frame for the display
    translate ([
            display_outer_offset_x - case_thickness - slackness_display / 2,
            display_outer_offset_y - case_thickness - slackness_display / 2,
            case_thickness]) {
        difference() {
            cube([
                display_outer_width + 2 * case_thickness + slackness_display,
                display_outer_height + 2 * case_thickness + slackness_display,
                display_outer_thickness]);
            translate([case_thickness,case_thickness,-display_outer_thickness / 2]) cube([
                display_outer_width + slackness_display,
                display_outer_height + slackness_display,
                display_outer_thickness * 2]);
        }
    }

    if (generate_pcb)
        translate([
                display_outer_offset_x,
                display_outer_offset_y,
                case_thickness / 2])
        translate([+display_outer_width / 2,+display_outer_height / 2,display_outer_thickness])
            rotate([180,0,0])
                translate([-display_outer_width / 2,-display_outer_height / 2])
                make_oled_SSD1306();
}

/*
** put everthing together side by side
*/
union()
{
    // the case itself
    if (generate_case && generate_case_lower)
        make_case_lower_shell();

    if (generate_case && generate_case_upper)
        if (generate_case_closed) {
            // close the case
            translate([case_length,0,case_lower_height + case_thickness])
                rotate([180,0,180])
                    make_case_upper_shell();
        }
        else {
            // put the upper case shell beside
            translate([0,case_width + gap,0])
                make_case_upper_shell();
        }

    if (generate_buttons)
        translate([0,(case_width + gap) * 2,0])
            for (button = [0:button_count - 1])
                translate([button * (button_radius * 2 + button_gap),0,0])
                    make_button((button) ? false : true);

    if (generate_sensorcase) {
        // the sensor case without any mounts
        translate([case_length + gap,0,0])
            make_sensorcase();
    }
    
    if (generate_sensormount) {
        if (generate_sensormount_clip_short) {
            // two short clips
            translate([case_length + gap - 2 * sensorcase_thickness,(sensorcase_radius + sensorcase_thickness)* 2 + gap,0])
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
            // one long clip
            translate([case_length + gap + sensormount_clip_bar_width + gap + sensormount_bar_width,0,0])
                 rotate([0,0,90])
                    make_sensormount();
        }
    }
}/**/
