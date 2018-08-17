# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>

pkgbase=python-pynacl
pkgname=(python-pynacl python2-pynacl)
pkgver=1.2.1
pkgrel=3

pkgdesc='Python binding to the Networking and Cryptography (NaCl) library'
url='https://pypi.python.org/pypi/PyNaCl'
arch=('x86_64')
license=('Apache')

depends=('libsodium')
makedepends=('python-setuptools' 'python-pycparser' 'python-cffi'
             'python2-setuptools' 'python2-pycparser' 'python2-cffi')

source=("https://pypi.org/packages/source/P/PyNaCl/PyNaCl-$pkgver.tar.gz")

sha512sums=('fe5c6d16332e5069c73764b85c11dcefa0169c200e2e1a7dc8e1c13b16db1ab989bd355b32226bd6c81ea68216285f8ace6b82f5bbb5d79d3b2c5b10dd5f9eef')

prepare() {
	cp -a PyNaCl-$pkgver{,-python2}
}

build() {
	export SODIUM_INSTALL=system

	cd "$srcdir"/PyNaCl-$pkgver
	python setup.py build

	cd "$srcdir"/PyNaCl-$pkgver-python2
	python2 setup.py build
}

package_python-pynacl() {
	depends=('libsodium' 'python' 'python-six' 'python-cffi')

	export SODIUM_INSTALL=system

	cd PyNaCl-$pkgver
	python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

package_python2-pynacl() {
	depends=('libsodium' 'python2' 'python2-six' 'python2-cffi')

	export SODIUM_INSTALL=system

	cd PyNaCl-$pkgver-python2
	python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim: set ts=4 sw=4 tw=0 ft=PKGBUILD :
