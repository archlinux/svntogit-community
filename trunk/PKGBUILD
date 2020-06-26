# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=fira-sans
pkgname=(ttf-fira-sans otf-fira-sans)
pkgver=4.301
_commit=f54eeb3124c63fe9b5bcd36d09d1cd46788cd15e
pkgrel=2
epoch=1
pkgdesc="Mozilla's typeface designed for Firefox OS"
arch=('any')
license=('custom:OFL')
url='https://github.com/mozilla/Fira'
source=("$pkgbase-$_commit.tar.gz::https://github.com/bBoxType/FiraSans/archive/$_commit.tar.gz")
sha512sums=('56fde0b2a76d11dd663851290b655949191011580dfc61576294c52f1b2f0be2d8a8963ed731ef21c258398caa278ec516481fad98ab5d9cbcb4d2705664ec21')

function _package {
    cd FiraSans-$_commit/Fira_Sans_4_3/Fonts

    case "$1" in
        ttf-fira-sans)
            pkgdesc="Mozilla's sans-serif typeface designed for Firefox OS"
            cd Fira_Sans_TTF_4301
            fonts=(*/*/FiraSans*.ttf)
            installdir=TTF;;
        otf-fira-sans)
            pkgdesc="Mozilla's sans-serif typeface designed for Firefox OS"
            cd Fira_Sans_OTF_4301
            fonts=(*/*/FiraSans*.otf)
            installdir=OTF;;
    esac

    # Prepare destination directory
    install -dm755 "$pkgdir/usr/share/fonts/$installdir"

    # Install fonts
    for font in "${fonts[@]}"; do
        install -m644 "$font" "$pkgdir/usr/share/fonts/$installdir"
    done

    install -D -m644 ../../../OFL.txt "$pkgdir/usr/share/licenses/$pkgname/OFL.txt"
}

for _pkgname in ${pkgname[@]}; do
    eval "function package_$_pkgname() { _package $_pkgname; }"
done
