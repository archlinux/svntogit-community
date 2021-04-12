# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Fabio Volpe <volpefabio@gmail.com>

pkgname=python-sphinx
pkgver=3.5.4
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
sha256sums=('19010b7b9fa0dc7756a6e105b2aacd3a80f798af3c25c273be64d7beeb482cb1'
            'SKIP')
b2sums=('8740714dfaf3733bf57d0b277315b4e7b5cad86247ea30dcbc4f5dadf5f5169329050b7be43ec8625c47df9dcc19afcc6c4d782725c7007f8178b7eb7be7dc05'
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

  # Remove created cache files for reproduciblity with rebuilderd
  find tests -type d -name __pycache__ -exec rm -r {} +
}

package() {
  cd Sphinx-$pkgver
  export PYTHONHASHSEED=0
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
