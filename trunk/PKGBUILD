pkgname=python-srcinfo
pkgver=0.0.1
pkgrel=1

pkgdesc="Simple .SRCINFO parsing library"
url='https://github.com/kyrias/python-srcinfo'
arch=('any')
license=('ISC')

depends=('python' 'python-setuptools' 'python-parse')

source=(python-srcinfo-"$pkgver".tar.gz::"https://github.com/kyrias/python-srcinfo/archive/$pkgver.tar.gz")

md5sums=('9eb6917d2cdb15dc8ac60d7074e8b777')

package() {
	cd python-srcinfo-"$pkgver"
	python setup.py install --root="$pkgdir" --optimize=1
}
