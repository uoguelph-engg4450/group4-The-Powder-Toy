#include "simulation/Elements.h"

//#TPT-Directive ElementClass Element_SCON PT_SCON 187
Element_SCON::Element_SCON()
{
	Identifier = "DEFAULT_PT_SCON";
	Name = "SCON";
	Colour = PIXPACK(0x405050);
	MenuVisible = 1;
	MenuSection = SC_ELEC;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 2;

	Weight = 100;

	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 0;
	Description = "Will only conduct to other SCON with same temperature value";

	Properties = TYPE_SOLID|PROP_CONDUCTS|PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &Element_SCON::update;
	Graphics = &Element_SCON::graphics;
}

//#TPT-Directive ElementHeader Element_SCON static int update(UPDATE_FUNC_ARGS)
int Element_SCON::update(UPDATE_FUNC_ARGS)
{
	parts[i].tmp = floor((parts[i].temp)/10)*10;
	return 0;
}

//#TPT-Directive ElementHeader Element_SCON static int graphics(GRAPHICS_FUNC_ARGS)
int Element_SCON::graphics(GRAPHICS_FUNC_ARGS)
{
	int q = floor((cpart->temp)/10);
	*colr = sin(0.0628f*q + 2) * 127 + 128;
	*colg = sin(0.0628f*q + 0) * 127 + 128;
	*colb = sin(0.0628f*q + 4) * 127 + 128;
	*pixel_mode |= EFFECT_DBGLINES;
	return 0;
}


Element_SCON::~Element_SCON() {}
