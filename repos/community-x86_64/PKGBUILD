# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>

pkgbase=python-pynacl
pkgname=(python-pynacl python2-pynacl)
pkgver=1.1.1
pkgrel=1

pkgdesc='Python binding to the Networking and Cryptography (NaCl) library'
url='https://pypi.python.org/pypi/PyNaCl'
arch=('i686' 'x86_64')
license=('Apache')

depends=('libsodium')
makedepends=('python-setuptools' 'python-pycparser' 'python-cffi'
             'python2-setuptools' 'python2-pycparser' 'python2-cffi')

source=("https://pypi.org/packages/source/P/PyNaCl/PyNaCl-$pkgver.tar.gz")

md5sums=('c1b11f6cd49f0302a63684cca626b2d5')

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
	depends=('libsodium' 'python' 'python-six')

	export SODIUM_INSTALL=system

	cd PyNaCl-$pkgver
	python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

package_python2-pynacl() {
	depends=('libsodium' 'python2' 'python2-six')

	export SODIUM_INSTALL=system

	cd PyNaCl-$pkgver-python2
	python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim: set ts=4 sw=4 tw=0 ft=PKGBUILD :
