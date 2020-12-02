# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: xantares

pkgname=python-sphinx-alabaster-theme
pkgver=0.7.12
pkgrel=6

pkgdesc="Sphinx default theme"
url='https://github.com/bitprophet/alabaster'
arch=('any')
license=('custom:BSD')

depends=('python')
makedepends=('python-setuptools' 'python2-setuptools')

source=("https://pypi.org/packages/source/a/alabaster/alabaster-$pkgver.tar.gz")

md5sums=('3591827fde96d1dd23970fb05410ed04')

build() {
	cd alabaster-"$pkgver"
	python setup.py build
}

package() {
	cd alabaster-"$pkgver"
	python setup.py install --root="$pkgdir" --optimize=1

	install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/"$pkgname"/LICENSE
}
