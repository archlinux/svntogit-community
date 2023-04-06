# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-configargparse
pkgver=1.5.3
pkgrel=3
pkgdesc='A drop-in replacement for argparse that allows options to also be set via config files and/or environment variables'
arch=('any')
url='https://github.com/bw2/ConfigArgParse'
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-tests' 'python-yaml')
optdepends=('python-yaml: for YAML support')
source=("https://github.com/bw2/ConfigArgParse/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('bdc0340bd92cfd5319743a4860af80fc2352f38b156031856c2b39b8c8ad59461281009030c4451dd464334a829b8143c765979cfc9b8ccbe9fbdcb0e08ac7b4')

build() {
  cd ConfigArgParse-$pkgver
  python setup.py build
}

check() {
  cd ConfigArgParse-$pkgver
  pytest
}

package() {
  cd ConfigArgParse-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
