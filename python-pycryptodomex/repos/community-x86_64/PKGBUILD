# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>

pkgbase=python-pycryptodomex
pkgname=('python-pycryptodomex' 'python2-pycryptodomex')
pkgver=3.9.0
pkgrel=1

pkgdesc='A self-contained Python package of low-level cryptographic primitives'
url='https://www.pycryptodome.org/'
arch=('x86_64')
license=('BSD')

makedepends=('python-setuptools'
             'python2-setuptools')

source=("https://pypi.org/packages/source/p/pycryptodomex/pycryptodomex-$pkgver.tar.gz")
sha512sums=('0ffc76780bee46a1ef38b131804ba63d511a57ad6b173366ee1ae2ac81e7718546e4c29a538fcc547c272f52ab679c45ed9de273fe57fb6ebc365d940aaa4cfa')

prepare() {
	cp -a pycryptodomex-$pkgver{,-python2}
}

build() {
	cd "$srcdir"/pycryptodomex-$pkgver
	python setup.py build

	cd "$srcdir"/pycryptodomex-$pkgver-python2
	python2 setup.py build
}

package_python-pycryptodomex() {
	depends=('python')

	cd pycryptodomex-$pkgver
	python setup.py install --root="$pkgdir" --optimize=1 --skip-build

	install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}

package_python2-pycryptodomex() {
	depends=('python2')

	cd pycryptodomex-$pkgver-python2
	python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build

	install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}
