# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=3.0.3
pkgrel=1
pkgdesc='Python documentation generator'
arch=('any')
url=http://www.sphinx-doc.org/
license=('BSD')
depends=('python-babel'
         'python-docutils'
         'python-imagesize'
         'python-jinja'
         'python-pygments'
         'python-requests'
         'python-setuptools'
         'python-snowballstemmer'
         'python-sphinx-alabaster-theme'
         'python-sphinxcontrib-'{{apple,dev,html}help,jsmath,qthelp,serializinghtml})
#checkdepends=('cython'
#              'imagemagick' 'librsvg'
#              'python-html5lib'
#              'python-pytest'
#              'texlive-fontsextra' 'texlive-latexextra')
optdepends=('imagemagick: for ext.imgconverter'
            'texlive-latexextra: for generation of PDF documentation')
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc})
sha256sums=('62edfd92d955b868d6c124c0942eba966d54b5f3dcb4ded39e65f74abac3f572'
            'SKIP')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07') # Takayuki Shimizukawa

build() {
  cd Sphinx-$pkgver
  make build
}

#check() {
#  cd Sphinx-$pkgver
#  LC_ALL="en_US.UTF-8" make test
#  rm -r tests
#}

package() {
  cd Sphinx-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
