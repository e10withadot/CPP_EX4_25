namespace contain {
	template<class K>
	class MyContainer {
		private:
			int SIZE;
			K* ARR;
		public:
			MyContainer();
			MyContainer(int size);
			MyContainer(K arr[]);
			void add();
			void remove();
			int size();
	}
}
