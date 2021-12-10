# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: lilydjwg <lilydjwg@gmail.com>
# Contributor: lilac <lilac@build.archlinuxcn.org>
# Contributor: Dimitris Kiziridis <ragouel@outlook.com>

_name=charset-normalizer
pkgname=python-charset-normalizer
pkgver=2.0.4
pkgrel=3
pkgdesc='Encoding and language detection alternative to chardet'
arch=(any)
url=https://github.com/ousret/charset_normalizer
license=(MIT)
depends=(python)
makedepends=(
  git
  python-setuptools
)
checkdepends=(python-pytest)
_tag=558d1e20c0d7cbdba9e207742cc9f2791649a425
source=(git+https://github.com/Ousret/charset_normalizer.git#tag=${_tag})
b2sums=(SKIP)

pkgver() {
  cd charset_normalizer
  git describe --tags
}

build() {
  cd charset_normalizer
  python setup.py build
}

check() {
  cd charset_normalizer
  python setup.py test
}

package() {
  cd charset_normalizer
  python setup.py install --root=$pkgdir --optimize=1 --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}"/usr/share/licenses/python-charset-normalizer/
}

# vim: ts=2 sw=2 et:
