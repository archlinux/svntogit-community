# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=3.2.1
pkgrel=2
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
source=("https://pypi.org/packages/source/S/Sphinx/Sphinx-$pkgver.tar.gz"{,.asc}
        $pkgname-pygments-2.7.patch::https://github.com/sphinx-doc/sphinx/commit/85b24a2e88ea.patch)
sha256sums=('321d6d9b16fa381a5306e5a0b76cd48ffbc588e6340059a729c6fdd66087e0e8'
            'SKIP'
            '6b790f4b3b540924a6a7861452fcbac8123f1e0a6c1765f5caafd7cb94fcecec')
validpgpkeys=('8A11B79A5D0D749A66F0A030102C2C17498D6B9E'  # Takeshi KOMIYA
              'E9BEABB07E7B9CC3F56E62C91425F8CE5EBA0E07') # Takayuki Shimizukawa

prepare() {
  cd Sphinx-$pkgver

  # Fix test failure with pygments 2.7
  patch -Np1 -i ../$pkgname-pygments-2.7.patch
}

build() {
  cd Sphinx-$pkgver
  make build
}

check() {
  cd Sphinx-$pkgver
  LC_ALL="en_US.UTF-8" make test
  rm -r tests
}

package() {
  cd Sphinx-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
