//
// Created by Raiix on 2021/7/14.
// Edited by Razoric on 2021/11/xx
//

#ifndef GODOT_SPINECONSTANT_H
#define GODOT_SPINECONSTANT_H

#include <Godot.hpp>

class SpineConstant : public godot::Reference {
	GODOT_CLASS(SpineConstant, godot::Reference);

public:
	static void _register_methods();

public:
	enum MixBlend {
		MixBlend_Setup = 0,
		MixBlend_First,
		MixBlend_Replace,
		MixBlend_Add
	};

	enum MixDirection {
		MixDirection_In = 0,
		MixDirection_Out
	};

	enum PropertyId {
		Property_Rotate = 1 << 0,
		Property_X = 1 << 1,
		Property_Y = 1 << 2,
		Property_ScaleX = 1 << 3,
		Property_ScaleY = 1 << 4,
		Property_ShearX = 1 << 5,
		Property_ShearY = 1 << 6,
		Property_Rgb = 1 << 7,
		Property_Alpha = 1 << 8,
		Property_Rgb2 = 1 << 9,
		Property_Attachment = 1 << 10,
		Property_Deform = 1 << 11,
		Property_Event = 1 << 12,
		Property_DrawOrder = 1 << 13,
		Property_IkConstraint = 1 << 14,
		Property_TransformConstraint = 1 << 15,
		Property_PathConstraintPosition = 1 << 16,
		Property_PathConstraintSpacing = 1 << 17,
		Property_PathConstraintMix = 1 << 18
	};
    
    void _init();

	int get_MixBlend_Setup() const;
	int get_MixBlend_First() const;
	int get_MixBlend_Replace() const;
	int get_MixBlend_Add() const;
	int get_MixDirection_In() const;
	int get_MixDirection_Out() const;
	int get_Property_Rotate() const;
	int get_Property_X() const;
	int get_Property_Y() const;
	int get_Property_ScaleX() const;
	int get_Property_ScaleY() const;
	int get_Property_ShearX() const;
	int get_Property_ShearY() const;
	int get_Property_Rgb() const;
	int get_Property_Alpha() const;
	int get_Property_Rgb2() const;
	int get_Property_Attachment() const;
	int get_Property_Deform() const;
	int get_Property_Event() const;
	int get_Property_DrawOrder() const;
	int get_Property_IkConstraint() const;
	int get_Property_TransformConstraint() const;
	int get_Property_PathConstraintPosition() const;
	int get_Property_PathConstraintSpacing() const;
	int get_Property_PathConstraintMix() const;
    
    void noset(int v);
};

#endif //GODOT_SPINECONSTANT_H
