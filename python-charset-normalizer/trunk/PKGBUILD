# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: lilydjwg <lilydjwg@gmail.com>
# Contributor: lilac <lilac@build.archlinuxcn.org>
# Contributor: Dimitris Kiziridis <ragouel@outlook.com>

pkgname=python-charset-normalizer
pkgver=3.0.0
pkgrel=1
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
_tag=0ec52eff710ede4924eb0bb2a243b781ea547cb6
source=(git+https://github.com/Ousret/charset_normalizer.git#tag=${_tag})
b2sums=(SKIP)

pkgver() {
  cd charset_normalizer
  _version=$(git describe --tags)
  sed "s/2.1.0/${_version}/" -i charset_normalizer/version.py
  echo ${_version}
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
