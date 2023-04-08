# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zeep
pkgver=4.2.1
pkgrel=2
pkgdesc="A fast and modern Python SOAP client"
arch=('any')
license=('MIT')
url="https://docs.python-zeep.org"
depends=('python-attrs' 'python-isodate' 'python-lxml' 'python-platformdirs' 'python-requests'
         'python-requests-toolbelt' 'python-requests-file' 'python-pytz')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-freezegun' 'python-pretend' 'python-pytest-cov'
              'python-requests-mock' 'python-pytest-httpx' 'python-pytest-asyncio' 'python-aiohttp'
              'python-aioresponses' 'python-xmlsec')
source=("https://github.com/mvantellingen/python-zeep/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('e708fcba7330088f7feee0d4ae64fa5480dcdff433e1a450f16ba90682b46fb9f0a335e96327dc70fe98e543697968609059bfac3bbd2f689d22ff51df95510f')

prepare() {
  sed -i -e 's/==/>=/' -e '/flake8/d' -e '/isort/d' python-zeep-$pkgver/setup.py
}

build() {
  cd python-zeep-$pkgver
  python setup.py build
} 

check() {
  cd python-zeep-$pkgver
  PYTHONPATH="$PWD"/build/lib pytest
}

package() {
  cd python-zeep-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
