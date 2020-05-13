# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>

pkgname=python-pynacl
pkgver=1.3.0
pkgrel=4

pkgdesc='Python binding to the Networking and Cryptography (NaCl) library'
url='https://pypi.python.org/pypi/PyNaCl'
arch=('x86_64')
license=('Apache')

depends=('libsodium')
depends=('libsodium' 'python' 'python-six' 'python-cffi')
makedepends=('python-setuptools' 'python-pycparser')

source=("https://pypi.org/packages/source/P/PyNaCl/PyNaCl-$pkgver.tar.gz")

sha512sums=('1762d7d9add6ca59ce83e394071861f78f27d0f06ad1481255ebb66023186127e1a67b49a2c2f51bcbd97bdd151a3a2adea099c47c2a9f456dda5e3b1508af50')

build() {
	export SODIUM_INSTALL=system

	cd "$srcdir"/PyNaCl-$pkgver
	python setup.py build
}

package() {
	export SODIUM_INSTALL=system

	cd PyNaCl-$pkgver
	python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim: set ts=4 sw=4 tw=0 ft=PKGBUILD :
