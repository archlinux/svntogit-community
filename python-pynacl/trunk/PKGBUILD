# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>

pkgbase=python-pynacl
pkgname=(python-pynacl python2-pynacl)
pkgver=1.3.0
pkgrel=1

pkgdesc='Python binding to the Networking and Cryptography (NaCl) library'
url='https://pypi.python.org/pypi/PyNaCl'
arch=('x86_64')
license=('Apache')

depends=('libsodium')
makedepends=('python-setuptools' 'python-pycparser' 'python-cffi'
             'python2-setuptools' 'python2-pycparser' 'python2-cffi')

source=("https://pypi.org/packages/source/P/PyNaCl/PyNaCl-$pkgver.tar.gz")

sha512sums=('1762d7d9add6ca59ce83e394071861f78f27d0f06ad1481255ebb66023186127e1a67b49a2c2f51bcbd97bdd151a3a2adea099c47c2a9f456dda5e3b1508af50')

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
