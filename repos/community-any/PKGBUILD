# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=3.5.0
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
checkdepends=('cython'
              'imagemagick' 'librsvg'
              'python-html5lib'
              'python-pytest'
              'texlive-fontsextra' 'texlive-latexextra')
optdepends=('imagemagick: for ext.imgconverter'
            'texlive-latexextra: for generation of PDF documentation')
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc})
sha256sums=('deb468efb3abaa70d790add4147d18782d86fdeacf648d6e8afb7a99807f1546'
            'SKIP')
b2sums=('7a6cf06264a62d6adbb79f80120e1182a37a73e3f600f30325a6c32d58423e4f7d02bf9d737c31c5ba7f91e23e6e19a59486c58ec0d4e31636ac39ffce6a46b0'
        'SKIP')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA <i.tkomiya@gmail.com>
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07') # Takayuki Shimizukawa <shimizukawa@gmail.com>

build() {
  cd Sphinx-$pkgver
  make build
}

check() {
  cd Sphinx-$pkgver
  LC_ALL="en_US.UTF-8" make test
}

package() {
  cd Sphinx-$pkgver
  export PYTHONHASHSEED=0
  rm -r tests
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
