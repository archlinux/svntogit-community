# Maintainer: Johannes Löthberg <johannes@kyriasis.com>

pkgname=python-hiredis
pkgver=2.0.0
pkgrel=4

pkgdesc='Non-blocking redis client for python'
url='https://pypi.org/project/hiredis/'
arch=('x86_64')
license=('Apache')

depends=('python')
makedepends=('python-setuptools')

source=("https://pypi.org/packages/source/h/hiredis/hiredis-$pkgver.tar.gz")

sha256sums=('81d6d8e39695f2c37954d1011c0480ef7cf444d4e3ae24bc5e89ee5de360139a')

build() {
	cd "$srcdir"/hiredis-$pkgver
	python setup.py build
}

package() {
	cd hiredis-$pkgver
	python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim: set ts=4 sw=4 tw=0 ft=PKGBUILD :
