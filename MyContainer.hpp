namespace contain {
	template<class K>
	class MyContainer {
		private:
			int SIZE;
			int ITEMS;
			K ARR[];
		public:
			MyContainer() : ITEMS(0), SIZE(0) {}
			MyContainer(K arr[]) {
				int size = sizeof(arr) / sizeof(arr[0]);
				SIZE = size;
				ITEMS = size;
				for (int i = 0; i < size; i++) {
					ARR[i] = arr[i];
				}

}
			void add(K item) {
				if (ITEMS < SIZE-1) {
					ARR[ITEMS] = item;
					ITEMS++;
				}
}
			void remove() {
				ARR[ITEMS--] = nullptr;
}
			int size() {
				return ITEMS;
}
	}
}
