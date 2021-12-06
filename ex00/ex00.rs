struct Vector<'a, K> {
	arr: &'a mut [K],
}

impl<'a, K: std::ops::AddAssign + std::fmt::Display> Vector<'a, K> {
	fn from(init_array: &'a [K]) -> Self {
		Self {
			arr: init_array,
		}
	}
	fn add(&mut self, v: &Vector<K>) -> &mut Self {
		if self.arr.len() != v.arr.len() {
			return self;
		}
		for i in 0..self.arr.len() {
			self.arr[i] += v.arr[i];
		}
		return self;
	}

	// fn sub(&mut self, v: &Vector<K>) {

	// }

	// fn scl(&mut self, a: K) {
		
	// }
	pub fn Display(& self) {
		for i in 0..self.arr.len() {
			println!("{}", self.arr[i]);
		}
	}
}

fn main() {
	let mut u = Vector::from(&[2., 3.]);
	let v = Vector::from(&[5., 7.]);
	u.add(&v);
	u.Display();
	// [7.0]
	// [10.0]

	// let mut u = Vector::from([2., 3.]);
	// let v = Vector::from([5., 7.]);
	// u.sub(v);
	// println!("{}", u);
	// // [-3.0]
	// // [-4.0]

	// let mut u = Vector::from([2., 3.]);
	// u.scl(2.);
	// println!("{}", u);
	// // [4.0]
}