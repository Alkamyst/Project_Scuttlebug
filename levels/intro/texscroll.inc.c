void scroll_ScuttlePirate_Title_Treasure_Chest_mesh_vtx_8() {
	int i = 0;
	int count = 92;
	int width = 16 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ScuttlePirate_Title_Treasure_Chest_mesh_vtx_8);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_actor_dl_ScuttlePirate_Title() {
	scroll_ScuttlePirate_Title_Treasure_Chest_mesh_vtx_8();
}
