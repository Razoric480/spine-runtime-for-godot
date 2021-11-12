//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineIkConstraintData.h"

void SpineIkConstraintData::_register_methods() {
	godot::register_method("get_all_bone_data", &SpineIkConstraintData::get_bones);
	godot::register_method("get_target", &SpineIkConstraintData::get_target);
	godot::register_method("set_target", &SpineIkConstraintData::set_target);
	godot::register_method("get_bend_direction", &SpineIkConstraintData::get_bend_direction);
	godot::register_method("set_bend_direction", &SpineIkConstraintData::set_bend_direction);
	godot::register_method("get_compress", &SpineIkConstraintData::get_compress);
	godot::register_method("set_compress", &SpineIkConstraintData::set_compress);
	godot::register_method("get_stretch", &SpineIkConstraintData::get_stretch);
	godot::register_method("set_stretch", &SpineIkConstraintData::set_stretch);
	godot::register_method("get_uniform", &SpineIkConstraintData::get_uniform);
	godot::register_method("set_uniform", &SpineIkConstraintData::set_uniform);
	godot::register_method("get_mix", &SpineIkConstraintData::get_mix);
	godot::register_method("set_mix", &SpineIkConstraintData::set_mix);
	godot::register_method("get_softness", &SpineIkConstraintData::get_softness);
	godot::register_method("set_softness", &SpineIkConstraintData::set_softness);
}

SpineIkConstraintData::SpineIkConstraintData() {}
SpineIkConstraintData::~SpineIkConstraintData() {}

void SpineIkConstraintData::_init() {}

godot::Array SpineIkConstraintData::get_bones() {
	auto bs = get_spine_data()->getBones();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineBoneData>(NULL);
		else {
			godot::Ref<SpineBoneData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Ref<SpineBoneData> SpineIkConstraintData::get_target() {
	auto b = get_spine_data()->getTarget();
	if (b == NULL)
		return NULL;
	godot::Ref<SpineBoneData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}
void SpineIkConstraintData::set_target(godot::Ref<SpineBoneData> v) {
	if (v.is_valid()) {
		get_spine_data()->setTarget(v->get_spine_object());
	} else {
		get_spine_data()->setTarget(NULL);
	}
}

int SpineIkConstraintData::get_bend_direction() {
	return get_spine_data()->getBendDirection();
}
void SpineIkConstraintData::set_bend_direction(int v) {
	get_spine_data()->setBendDirection(v);
}

bool SpineIkConstraintData::get_compress() {
	return get_spine_data()->getCompress();
}
void SpineIkConstraintData::set_compress(bool v) {
	get_spine_data()->setCompress(v);
}

bool SpineIkConstraintData::get_stretch() {
	return get_spine_data()->getStretch();
}
void SpineIkConstraintData::set_stretch(bool v) {
	get_spine_data()->setStretch(v);
}

bool SpineIkConstraintData::get_uniform() {
	return get_spine_data()->getUniform();
}
void SpineIkConstraintData::set_uniform(bool v) {
	get_spine_data()->setUniform(v);
}

float SpineIkConstraintData::get_mix() {
	return get_spine_data()->getMix();
}
void SpineIkConstraintData::set_mix(float v) {
	get_spine_data()->setMix(v);
}

float SpineIkConstraintData::get_softness() {
	return get_spine_data()->getSoftness();
}
void SpineIkConstraintData::set_softness(float v) {
	get_spine_data()->setSoftness(v);
}